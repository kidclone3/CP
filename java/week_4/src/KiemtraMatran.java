import java.util.Scanner;

public class KiemtraMatran {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a[][] = new int[n][n];
        int b[] = new int[n*n + 1] ;
        boolean failed = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = sc.nextInt();
                if (a[i][j] <= n*n)
                    b[a[i][j]] = 1;
                else {
                    failed = true;
                }
            }
        }
        if(failed) {
            System.out.println("NO");
            return;
        }
        for (int i = 1; i <= n*n ; i++) {
            if (b[i] != 1) {
                System.out.println("NO");
                return;
            }
        }
        System.out.println("YES");
    }
}
