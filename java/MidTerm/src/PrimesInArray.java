import java.util.Scanner;

public class PrimesInArray {
    static boolean isPrime(int n) {
        if (n < 2) return false;
        if (n % 2 == 0) return n == 2;
        for(int i = 2; i*i <= n; ++i) {
            if (n%i == 0) return false;
        }
        return true;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
            if (isPrime(a[i])) {
                System.out.print(a[i]+ " ");
            }
        }
    }
}
