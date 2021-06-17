import java.util.Scanner;

/**
 * Chương trình nhập một số nguyên dương n và ma trận nguyên A kích thước n x n 
 * sau đó kiểm tra xem các phần tử của ma trận có giá trị từ 1 đến n*n hay không
 * Nếu đúng in ra màn hình thông báo "YES", nếu sai, in ra thông báo "NO"
 * **/
public class KiemtraMatran{
    static boolean check(int[][] a) {
        int n = a.length;
        int[] dp = new int[(int) 1e6+5];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[a[i][j]]++;
            }
        }
        for (int i = 1; i <= n*n; i++) {
            if (dp[i] == 0) return false;
        }
        return true;
    }
    // viết mã lệnh ở đây
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] a = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = sc.nextInt();
            }
        }
        System.out.println((check(a) ? "YES" : "NO"));
    }
}