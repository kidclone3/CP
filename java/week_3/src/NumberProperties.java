// bai 8
public class NumberProperties {
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
        int n = Integer.parseInt(args[0]);
//        n so nguyen to dau tien
        for (int i = 2; i <= n; ++i) {
            if (isPrime(i)) {
                System.out.printf("%d ", i);
            }
        }
        System.out.println();

//        n so doi xung dau tien
        for (int i = 1; i <= n; ++i) {
            if (isPalindrome(i)) {
                System.out.print(i + " ");
            }
        }
        System.out.println();

//        n so Armstrong dau tien
        for (int i = 1; i <= n; ++i) {
            if (isArmstrong(i)) System.out.print(i + " ");
        }
        System.out.println();

//        n so hoan thien dau tien
        for (int i = 1; i <= n; ++i) {
            if (isPerfectNumber(i)) {
                System.out.print(i + " ");
            }
        }
    }
}
