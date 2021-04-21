import java.util.Scanner;

public class TrigonometricFunctions {
    public static double factorial(int n) {
        double ans = 1;
        if (n==0) return ans;
        for (int i = 1; i<= n; ++i) {
            ans *= i;
        }
        return ans;
    }
    public static double sin(double x) {
        double ans = 0;
        for (int i = 1; i <= 50; ++i) {
            double tmp = 1;
            if (i % 2 == 0) tmp = -1;
            tmp *= Math.pow(x, 2 * i - 1) / factorial(2 * i - 1);
            ans += tmp;
        }
        return ans;
    }
    public static double cos(double x) {
        double ans = 1;
        for (int i = 1; i <= 50; ++i) {
            double tmp = 1;
            if (i % 2 != 0) tmp = -1;
            tmp *= Math.pow(x, 2 * i) / factorial(2 * i);
            ans += tmp;
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double x = sc.nextDouble();
        System.out.println(sin(x));
        System.out.println(cos(x));
    }
}
