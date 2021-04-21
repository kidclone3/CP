import java.util.Scanner;

public class bai4 {
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

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
//        Viet so nguyen to.
        {
            int n = sc.nextInt();
            for (int i = 2; i <= n; ++i) {
                if (isPrime(i)) {
                    System.out.print(i + " ");
                }
            }
            System.out.println();
        }
    }

}
