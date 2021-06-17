import java.util.ArrayList;
import java.util.Scanner;

public class XoaCot {
    static Integer[][] deleteCol(Integer[][] a, int k) {
        int n = a.length;
        int m = a[0].length;
        Integer[][] ans = new Integer[n][m-1];
        for (int i = 0; i < n; i++) {
            ArrayList<Integer> arr = new ArrayList<>();
            for (int j = 0; j < m; j++) {
                if (j != k) arr.add(a[i][j]);
            }
            ans[i] = arr.toArray(ans[i]);
        }
        return ans;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int k = sc.nextInt();
        Integer[][] a = new Integer[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = sc.nextInt();
            }
        }
        Integer[][] ans = deleteCol(a, k);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m - 1; j++) {
                System.out.print(ans[i][j] + " ");
            }
            System.out.println();
        }
    }
}
