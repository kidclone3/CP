// Anonymous pipes between parent and child
// Parent sends a string to child using pipe a
// Child converts the string to uppercase and sends back to parent, using pipe b
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
    char buf[255];
    int fd_a[2], fd_b[2], pid;
    
    memset(buf, 0, 255);
    // create 2 pipes a and b
    if ((pipe(fd_a) < 0) || (pipe(fd_b) < 0))
        exit(-1);
  
    if ((pid = fork()) > 0) { // parent
        close(fd_a[0]); close(fd_b[1]);
        // send a message to the child using pipe a
        printf("Type a message to the child: ");
        fgets(buf, 254, stdin); // get user's input, 254 chars maximum
        // ...                     // send via pipe a
        write(fd_a[1], buf, 254);
        // wait for a message from the child using pipe b
        // ...    // read from pipe b to buffer buf
        read(fd_b[0], buf, 254);
        printf("Message replied from the child: %s\n", buf);
        wait(NULL); // wait for the child to exit
    }
    else { //child
        close(fd_a[1]); close(fd_b[0]);
        
        // read a string of max 255 chars from pipe a to buffer buf
        // ...
        read(fd_a[0], buf, 254);
        // convert to uppercase
        for (int i=0; i<strlen(buf); i++)
            buf[i] = toupper(buf[i]);
        // send back to parent via pipe b
        // ...
        write(fd_b[1], buf, 254);
    }
    return 0;
}
