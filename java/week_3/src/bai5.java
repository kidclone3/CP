import java.util.Scanner;

public class bai5 {
    public static boolean isPrime(int k) {
        if (k == 2) return true;
        if (k <=1 || k % 2 == 0) return false;
        for (int i = 2; i * i <= k; ++i) {
            if (k % i == 0) {
                return false;
            }
        }
        return true;
    }
    public static boolean isPerfectNumber(int k) {
        if (isPrime(k)) return false;
        if (k <= 1) return false;
        int tmp = 1;
        for (int i = 2; i * i <= k; ++i) {
            if (k % i == 0) {
                if (i != (k/i)) tmp += i + (k/i);
                else tmp += i;
            }
        }
        return tmp == k;
    }

    public static void main(String[] args) {
        //        Viet so hoan hao
        Scanner sc = new Scanner(System.in);
        {
            int n = sc.nextInt();
//            System.out.println(isPerfectNumber(6));
            for (int i = 1; i <= n; ++i) {
                if (isPerfectNumber(i)) {
                    System.out.print(i + " ");
                }
            }
            System.out.println();
        }
    }
}
