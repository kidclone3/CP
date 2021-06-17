import java.util.Scanner;

/** De5_bai1.java
 * Nhập vào số thực x và số nguyên dương n từ bàn phím (x nhập trước, n nhập sau).
 * Tính và in ra giá trị biểu thức f(x) = 2x^3 cos(3x) - 4x^2 + 3x cos(3x) - 12
 * */

public class De5_bai1{

    public static double F(double x, int n){ // tính và trả về f(x)
        // bổ sung mã lệnh
        //        System.out.println(ans);
        return 2*x*x*x * cos3x(x, n) - 4*x*x + 3*x * cos3x(x, n) - 12; // sửa giá trị trả về - nhưng cần đúng kiểu
    }
    public static double cos3x(double x, int n) { // tính và trả về coh(3x)
        // bổ sung mã lệnh
        double ans = 1.0;
        double tmp = -1 * (3*x) * (3*x) / 2;
        ans+=tmp;
        for (int i = 4; i <= 2*n; i+=2) {
            tmp = -1 * tmp *(3*x) * (3*x) / ((i) * (i-1));
            ans+=tmp;
        }
//        return Math.cos(3*x); // sửa giá trị trả về - nhưng cần đúng kiểu
        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double x = sc.nextDouble();
        int n = sc.nextInt();
        System.out.println(F(x, n));
//        F(x, n);
//        System.out.println(cos3x(x, n));
    }

    // phương thức main để thực hiện.
}