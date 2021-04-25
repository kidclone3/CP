import java.util.Scanner;

public class GroupArray {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a[] = new int[n];
        int b[] = new int[n];
        int j = 0;
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
            if (a[i] % 2 == 1) {
                b[j++] = a[i];
            }
        }
        for (int i = 0; i < n; i++) {
            if (a[i] % 2 == 0) {
                b[j++] = a[i];
            }
        }
        for (int i : b) {
            System.out.printf("%d ", i);
        }
    }
}
