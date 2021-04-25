import java.util.Scanner;

public class XoaCot {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int n = sc.nextInt();
        int k = sc.nextInt();
        int a[][] = new int[m][n];
        int b[][] = new int[m][n-1];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = sc.nextInt();
            }
        }
        for (int i = 0; i < m; i++) {
            int z = 0;
            for (int j = 0; j < n; j++) {
                if (j == k) continue;
                b[i][z] = a[i][j];
                z++;
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n-1; j++) {
                System.out.printf("%d ", b[i][j]);
            }
            System.out.println();
        }
    }
}
