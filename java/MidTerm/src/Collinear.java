import java.util.Scanner;

public class Collinear {
    static void printArray(int[] a) {
        for (int i = 0; i < a.length; i++) {
            System.out.print(a[i] + " ");
        }
        System.out.println();
    }
    static boolean isCollinear(int U[], int V[]) {
        try {
            double tmp = 1.0;
            boolean found = true;
            if (V[0] == 0) {
                if (U[0] != 0) return false;
                found = false;
            } else tmp = 1.0 * V[0] / U[0];
//            System.out.println(tmp);
            for (int i = 0; i < U.length; i++) {
                if (!found) {
                    if (U[i] != 0 && V[i] != 0) {
                        tmp = 1.0 * V[i] / U[i];
                        found = true;
                        continue;
                    }
                }
                double tmp2 = U[i]*tmp;
                if (Math.abs(tmp2 - 1.0 * V[i]) > 1e-6) {
                    return false;
                }
            }
            return true;
        }
        catch (Exception e) {
            return false;
        }
    }
    static int[] solve(int[][] a) {
        int rows = a.length;
        int cols = a[0].length;
        int[] ans = new int[cols];
        for (int j = 0; j < cols; j++) {
            int[] U = new int[rows];
            for (int i = 0; i < rows; i++) {
                U[i] = a[i][j];
            }
            for (int y = 0; y <= j; y++) {
                int[] V = new int[rows];
                for (int x = 0; x < rows; x++) {
                    V[x] = a[x][y];
                }
                if (isCollinear(U, V)) {
                    ans[j] = y;
                    break;
                }
            }
        }
        return ans;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] a = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = sc.nextInt();
            }
        }
        int[] ans = solve(a);
        for (int it : ans) {
            System.out.print(it + " ");
        }
    }
}
