import java.util.ArrayList;
import java.util.Scanner;

public class Bai2_de1 {
    public static int[][] inputMatrix(Scanner reader) {
        int n = reader.nextInt();
        int[][] ans = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                ans[i][j] = reader.nextInt();
            }
        }
        return ans;
    }
    public static boolean isUnitMatrix(int[][] arr) {
        int n = arr.length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i != j && arr[i][j] != '0') return false;
                if (i == j && arr[i][j] != '1') return false;
            }
        }
        return  true;
    }
    public static int minElement(int[] arr) {
        int mn = arr[0];
        for (int it : arr) {
            mn = Math.min(mn, it);
        }
        return mn;
    }
    public static int[] findRows(int[][] arr) {
        int mx = (int) -1e10;
        int n = arr.length;
        for (int i = 0; i < n; i++) {
            mx = Math.max(mx, minElement(arr[i]));
        }
        int c = 0;
        for (int[] it : arr) {
            if (minElement(it) == mx) {
                c++;
            }
        }
        int[] ans = new int[c];
        for (int i = 0, j = 0; i < n; i++) {
            if (minElement(arr[i]) == mx) {
                ans[j++] = i;
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[][] arr = inputMatrix(sc);
        int[] ans = findRows(arr);
        for(int it : ans) {
            System.out.print(it + " ");
        }
    }
}
