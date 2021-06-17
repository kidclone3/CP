/**
 * Hoàn thiện các phương thức trong lớp De5_bai2 theo các yêu cầu
 * như trong phần mô tả và đề bài. Các phương thức cần được giữ nguyên dạng
 * tên / danh sách tham đối/ kiểu trả về/ mẫu khai báo ....
 * Có thể bổ sung các phương thức khác nếu cần.
 * */
import java.util.Scanner;

public class De5_bai2{

    /* thực hiện nhập số nguyên m, n và trả lại mảng hai chiều m x n số nguyên nhập từ bàn phím */
    public static int[][] readMatrix(Scanner reader) {
        // bổ sung mã lệnh - có thể thay đổi giá trị trả về nhưng cần đúng kiểu
        int n = reader.nextInt();
        int m = reader.nextInt();
        int[][] a = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = reader.nextInt();
            }
        }
        return a;
    }

    /* thực hiện việc in mảng hai chiều Mtr ra màn hình dạng ma trận */
    public static void printMatrix(int[][] Mtr) {
        // bổ sung mã lệnh
        int n = Mtr.length;
        int m = Mtr[0].length;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                System.out.print(Mtr[i][j] + " ");
            }
            System.out.println();
        }
    }
    public static boolean isPalindrome(int k)
    {
        //add code here
        int tmp = k;
        int res = 0;
        while(tmp > 0) {
            res*=10;
            res+= tmp%10;
            tmp/=10;
        }
        return res == k;
    }
    /* liệt kê chỉ số dòng của các phần tử là số đối xứng trong cột thứ k ma trận Mtr */
    public static void listPalindrome(int[][] Mtr, int k) {
        // bổ sung mã lệnh
        int n = Mtr.length;
        for (int i = 0; i < n; i++) {
            if (isPalindrome(Mtr[i][k])) {
                System.out.print(Mtr[i][k] + " ");
            }
        }
        System.out.println();
    }

    /*  thực hiện tính và trả về giá trị trung bình các phần tử cột thứ k của Mtr */
    public static double avgCols(int[][] Mtr, int k) {
        // bổ sung mã lệnh - có thể thay đổi giá trị trả về nhưng cần đúng kiểu
        int n = Mtr.length;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += Mtr[i][k];
        }
        return 1.0*sum/n;
    }

    /* thực hiện việc tính và in giá trị trung bình các phần tử của các cột trong Mtr ra màn hình */
    public static void printColsAvg(int[][] Mtr)  {
        // bổ sung mã lệnh
        int n = Mtr.length;
        int m = Mtr[0].length;
        for (int j = 0; j < m; j++) {
            double ans = avgCols(Mtr, j);
            System.out.printf("%.3f ", ans);
        }
        System.out.println();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int[][] a = readMatrix(sc);
//        listPalindrome(a, 3);
        printColsAvg(a);
    }
}

//5.600 7.000 6.000 3.400 8.800
//5.600 7.000 6.000 3.400 8.800
//0 1 3