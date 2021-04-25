import java.util.Scanner;

/**
 * Hoàn thiện chương trình Collinear cho phép nhập 2 số nguyên m, n và mảng A
 * m x n phần tử nguyên. Kiểm tra và liệt kê các cột cộng tuyến theo yêu cầu
 * Giữ cấu trúc hàm kiểm tra isCollinear(int V[], int U[]), bổ sung các hàm/
 * phương thức khác để hoàn thành chương trình.
 * */

class Collinear{

    //Hoàn thiện định nghĩa hàm/phương thức kiểm tra 2 mảng cộng tuyến dưới đây
    public static boolean isCollinear(int V[], int U[]){
        double tmp = 1.0;
        if(U[0] != 0)
            tmp = ((double) U[0] / V[0]);
        // bổ sung mã của hàm/phương thức kiểm tra U, V có cộng tuyến hay không
        for(int i = 1; i < V.length; ++i) {
            if (U[i] == V[i] && U[i] == 0 ) continue;
            if(Math.abs(tmp * V[i] - (double) U[i]) > 1e-6)
            {
                return false;
            }
        }
        return true;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int n = sc.nextInt();
        int a[][] = new int[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = sc.nextInt();
            }
        }
        int ans[] = new int[n];
        int ans_i = 0;
        for (int j = 0; j < n; j++) {
            int u[] = new int[m];
            for (int i = 0; i < m; i++) {
                u[i] = a[i][j];
            }
            boolean yes = false;
            for (int z = 0; z < j; z++) {
                int v[] = new int[m];
                for (int i = 0; i < m; i++) {
                    v[i] = a[i][z];
                }
                if (isCollinear(v, u) && isCollinear(u, v)) {
                    ans[ans_i] = z;
                    ans_i ++;
                    yes = true;
                    break;
                }
            }
            if (!yes) {
                ans[ans_i] = j;
                ans_i++;
            }
        }
        for (int i : ans) {
            System.out.printf("%d ", i);
        }
    }
}
//0 1 2 3 4 0 4 7 8 4 10 11 12 8 14 11 11 0
//15 15
//        -2 -6 0 13 -2 -14 -7 7 -56 -4 14 0 -56 0 0
//        8 -9 5 -5 8 -11 15 -14 120 16 -28 0 120 5 0
//        14 -3 15 -5 14 5 14 -2 112 28 -4 8 112 -1 16
//        -7 -14 -6 3 -7 -2 -6 -5 -48 -14 -10 15 -48 -7 30
//        12 -14 15 6 12 -14 -6 -2 -48 24 -4 -11 -48 -13 -22
//        6 -6 3 15 6 8 -6 1 -48 12 2 -14 -48 -11 -28
//        -1 15 -8 -11 -1 -1 0 -1 0 -2 -2 -12 0 1 -24
//        -6 5 4 -8 -6 12 -2 -12 -16 -12 -24 12 -16 0 24
//        13 -5 -13 -4 13 1 6 -12 48 26 -24 1 48 10 2
//        0 -11 3 1 0 10 -11 -2 -88 0 -4 -1 -88 11 -2
//        -11 -4 3 -3 -11 1 15 5 120 -22 10 -3 120 6 -6
//        12 6 15 -10 12 15 12 6 96 24 12 3 96 14 6
//        -11 -3 -14 -9 -11 -9 6 9 48 -22 18 0 48 2 0
//        -1 -8 5 -12 -1 12 12 3 96 -2 6 -9 96 13 -18
//        12 -7 -7 5 12 2 0 -13 0 24 -26 -6 0 13 -12
