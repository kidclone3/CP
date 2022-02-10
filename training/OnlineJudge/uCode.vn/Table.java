import java.util.Scanner;

// package uCode.vn;

public class Table {
    // public static boolean check(char[][] a) {

    // }
    public static void main(String[] args) {
        char[][] a = new char[5][5];
        Scanner sc = new Scanner(System.in);
        boolean check = false;
        // Read 2d array //
        for (int i = 0; i<4 ; ++i) {
            String s = sc.nextLine();
            // char tmp = s[0];
            byte count = 1;
            for(int j = 0; j<4; ++j) {
                a[i][j] = s.charAt(j);
                if (j>0 && a[i][j] == a[i][j-1] && a[i][j] == 'X') count++;
                if (count == 4) check = true;
            }
        }
        // Check col;
        for (int i = 0; i < 4; ++i) {
            byte count = 1;
            for (int j = 1; j<4; ++j) {
                if (a[j][i] == a[j-1][i] && a[j][i] == 'X') count++;
            }
            if (count == 4) {
                check = true;
                break;
            }
        }
        // check Diagram
        for (int i=1; i<4; ++i) {
            byte count = 1;
            if (a[i][i] == a[i-1][i-1] && a[i][i]=='X') count++;
            if (count == 4) check = true;
        }
        if (check) System.out.print("yes");
        else System.out.print("no");
        sc.close();
    }
    
}
