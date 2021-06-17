import java.util.Scanner;

public class SumCols {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] a = new int[n][m];
        int[] ans = new int[m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = sc.nextInt();
                ans[j] += a[i][j];
            }
        }
        for(int it : ans) {
            System.out.print(it + " ");
        }
    }
}
