import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class NextRound {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n, k;
        n = sc.nextInt();
        k = sc.nextInt();
        Integer[] a = new Integer[n];
        int res = 0;
        for (int i = 0; i<n; ++i) {
            a[i] = sc.nextInt();
        }
        Arrays.sort(a, Collections.reverseOrder());
        int j = 1;
        for(int i = 1; i<n; ++i) {
            if (a[i]<=a[i-1]) k++;
            if (j==k) {
                System.out.println(n-k+1);
                return;
            }
        }
        System.out.println(0);
    }
}
