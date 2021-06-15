public class SampleMidterm {

    public static int sum(int n, int m) {
        int ans = (m + n) * (m - n + 1) / 2;
        return ans;
    }

    public static int multi(int n, int m) {
        int ans = 1;
        for (int i = n; i <= m ; i++) {
            ans *= i;
        }
        return ans;
    }

    public static boolean isArithmeticSequence(int[] a) {
        int n = a.length;
        if (n <= 2) return true;
        int d = a[1] - a[0];
        for (int i = 1; i < n; ++i) {
            if (a[i] - a[i-1] != d) return false;
        }
        return true;
    }

    public static boolean isGeometricSequence(int[] a) {
        int n = a.length;
        if (n <= 2) return true;
        double q = (a[1] * 1.0) / a[0];
        for (int i = 1; i < n; ++i) {
            if (a[i] / a[i-1] != q) return false;
        }
        return true;
    }

    public static boolean isPrime(int n) {
        if (n < 2) return false;
        if (n == 2) return true;
        if (n % 2 == 0) return false;
        for (int i = 2; i*i <= n; ++i) {
            if (n % i == 0) return false;
        }
        return true;
    }

    public static boolean isPerfectNum(int n) {
        int ans = 1;
        for (int i = 2; i*i <= n; ++i) {
            if (n % i == 0) {
                if (i != (n / i)) {
                    ans += i + n/i;
                }
                else ans += i;
            }
        }
        return ans == n;
    }

    public static int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }

    public static int lcm(int a, int b) {
        int _gcd = gcd(a, b);
        return a * b / _gcd;
    }

    public static int[] getMirror(int[] a) {
        int n = a.length;
        int[] ans = new int[n];
        for (int i = 0; i < n; ++i) {
            ans[i] = a[n-i-1];
        }
        return ans;
    }

    public static void speacialSort(int[] a) {
        int n = a.length;
        int chan, le;
        chan = le = 0;
        for (int i : a) {
            if (i % 2 == 0) {
                chan ++;
            }
            else le++;
        }
        int[] _chan = new int[chan];
        int[] _le = new int[le];
        for (int i = 0, j = 0, z = 0; i < n; ++i) {
            if (a[i] % 2 == 0) {
                _chan[j++] = a[i];
            }
            else _le[z++] = a[i];
        }
        for (int i = 0; i < chan - 1; i++) {
            for (int j = i; j < chan; j++) {
                if (_chan[i] > _chan[j]) {
                    int tmp = _chan[i];
                    _chan[i] = _chan[j];
                    _chan[j] = tmp;
                }
            }
        }
        for (int i = 0; i < le - 1; i++) {
            for (int j = i; j < le; j++) {
                if (_le[i] < _le[j]) {
                    int tmp = _le[i];
                    _le[i] = _le[j];
                    _le[j] = tmp;
                }
            }
        }
        for (int i = 0, j = 0, z = 0; i < n; i++) {
            if (j < chan) {
                a[i] = _chan[j++];
            }
            else a[i] = _le[z++];
        }
    }

    public static void main(String[] args) {
        int n = 4, m = 6;
        System.out.println("sum = "+sum(n,m));
        System.out.println("multiple = "+multi(n, m));
        int[] a = {1,2,3,4};
        int[] b = {1, 1, 1, 1};
        System.out.println("isArithmeticSequence a = "+isArithmeticSequence(a));
        System.out.println("isArithmeticSequence b = "+isArithmeticSequence(b));
        System.out.println("isGeometricSequence a = "+isGeometricSequence(a));
        System.out.println("isGeometricSequence b  = "+isGeometricSequence(b));

        int p = 7, k = 28;
        System.out.println("isPrime p = "+isPrime(p)+"; isPrime k = "+isPrime(k));
        System.out.println("isPerfectNum p = "+isPerfectNum(p)+"; isPerfectNum k = "+isPerfectNum(k));
        System.out.println("gcd (n, m) = "+ gcd(n, m));
        System.out.println("lcm (n,m) = "+lcm(n, m));

        int[] mirror = getMirror(a);
        if(mirror!=null)
        {
            System.out.println("a mirror:");
            for(int i = 0 ; i < mirror.length ; i++)
                System.out.print(mirror[i]+" ");
        }
        else
            System.out.println("null mirror");

        System.out.println();
        speacialSort(a);
        for (int i = 0; i < a.length; i++) {
            System.out.print(a[i]+" ");
        }
    }
}