import java.util.Scanner;

public class bai6 {
    public static boolean isPalindrome(int k) {
        int tmp = 0;
        int n = k;
        while(n > 0) {
            tmp *= 10;
            tmp += n % 10;
            n /= 10;
        }
        return tmp == k;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
//        System.out.println(isPalindrome(n));
        for (int i = n; i <= m; ++i) {
            if (isPalindrome(i)) {
                System.out.print(i + " ");
            }
        }
        System.out.println();
    }
}
