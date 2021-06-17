import java.util.Arrays;
import java.util.Scanner;

public class a {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

//        5 10
//        1 2
//        1 2 3 4 5
//        5 4 3 2 1
//        i => chup a[i] buc chat luong thap + b[i] buc anh chat luong cao => a[i].


        int n = sc.nextInt();
        int d = sc.nextInt();
        int aa = sc.nextInt();
        int bb = sc.nextInt();
        int[] a = new int[n];

        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
            a[i] = a[i]*aa;
        }
        for (int i = 0; i < n; i++) {
            int tmp = sc.nextInt();
            a[i] += tmp*bb;
        }
        Arrays.sort(a);
        int sum = 0;
        int i = 0;
        for (; i < n; ++i) {
            if (sum + a[i] > d) {
                break;
            }
            sum+=a[i];
        }
        System.out.println(i);
    }
}
