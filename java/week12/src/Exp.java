// Viết chương trình tính exp theo công thức khai triển Taylor được mô tả trong file Đề bài tinh_exp.pdf
// Khuôn mẫu các phương thức và lớp cần được giữ nguyên 
// Có thể bổ sung thêm các phương thức khác nếu cần!

import java.lang.Math.*;

public class Exp{

    // phương thức dblExp tính và trả về giá trị gần đúng của e^x
    public static double dblExp(double x, int n){
        //begin editing 
        double ans = 1;
        for (int i = 1; i <= n; ++i) {
            double tmp = 1;
            double tmp2 = x;
            for (int j = 2; j <= i; ++j) {
                tmp *= j;
                tmp2 *= x;
            }
            ans += tmp2 / tmp;

        }
        //end editing
        return Math.round(ans * 1000.0) / 1000.0;
    }

    public static void main(String args[]){
//        double x = Double.parseDouble(args[0]);
//        int n = Integer.parseInt(args[1]);
//        System.out.println(dblExp(x, n));
        System.out.println(dblExp(3, 3));

    }
}