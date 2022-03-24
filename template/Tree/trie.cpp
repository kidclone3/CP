#include <stdio.h>
#include <vector>
using namespace std;

// trie

class trie {
  public :
    struct node {
        int a[64];
        int value;
        int& operator[] (int i){ return a[i%64]; }
        node() { for (int i=0; i<64; i++) a[i]=0; value=0; }
    };
   
    vector <node> a;
   
    int& operator[] (char *s){
        int pos=0, i, c;
       
        for (i=0; c=s[i]; i++)
        {
            if (a[pos][c]==0) {
                a.push_back(node());
                a[pos][c] = a.size()-1;
            }
            pos=a[pos][c];
        }
        return a[pos].value;
    }
   
    void clear(){ a.clear(); a.push_back(node()); }
    trie(){ clear(); }
};

trie tr;

// main
int main(){
    int cnt=0;
    char s[2309];
    for(;;){
        gets(s);
        if (tr[s]==0) tr[s]=++cnt;
        printf("%s = %d\n", s, tr[s]);
    }
    return 0;   
}

// https://sites.google.com/site/kc97ble/container/trie-cpp