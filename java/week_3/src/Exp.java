import java.util.Scanner;

public class Exp {
    public static double factorial(int n) {
        double ans = 1;
        if (n==0) return ans;
        for (int i = 1; i<= n; ++i) {
            ans *= i;
        }
        return ans;
    }
    public static double dblExp(double x, int n) {
        double ans = 1;
        for (int i = 1; i <= n; ++i) {
            ans += Math.pow(x, i) / factorial(i);
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double x = sc.nextDouble();
        int n = sc.nextInt();
        System.out.println(dblExp(x, n));
    }
}
