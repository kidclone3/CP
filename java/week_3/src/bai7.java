import java.util.Scanner;

public class bai7 {
    public static boolean isArmstrong (int k) {
        int tmp = 0;
        int n = k;
        String s = Integer.toString(n);
        while(n > 0) {
            int digit = n % 10;
            int tmp1 = 1;
            for (int i = 0; i < s.length(); ++i) {
                tmp1 *= digit;
            }
            tmp += tmp1;
            n /= 10;
        }
        return tmp == k;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        System.out.println(isArmstrong(k));
        int n = sc.nextInt();
        for (int i = 1; i <= n; ++i) {
            if (isArmstrong(i)) System.out.print(i + " ");
        }
        System.out.println();
    }
}
