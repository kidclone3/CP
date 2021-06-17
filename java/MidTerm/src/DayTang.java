import java.util.Scanner;

public class DayTang {
    static boolean check(int[] a){
        int n = a.length;
        for (int i = 0; i < n - 1; i++) {
            if (a[i] >= a[i+1]) return false;
        }
        return true;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        System.out.println((check(a) ? "YES" : "NO"));
    }
}
