import java.util.Scanner;

public class phantichso {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int a[] = new int[n];
        int b[] = new int[n];
        for(int i = 0; i < n; ++i) {
            a[i] = sc.nextInt();
        }
        for(int i = 0; i < n; ++i) {
            b[i] = sc.nextInt();
            b[i] += a[i];
        }
        for(int i = 0; i < n; ++i) {
            System.out.printf("%d ", b[i]);
        }
    }
}
