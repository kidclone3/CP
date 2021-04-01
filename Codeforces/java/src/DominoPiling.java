import java.util.Scanner;

public class DominoPiling {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        long res = 0;
        res = Math.max(a*b/2, a/2 *b);
        System.out.println(res);
    }
}
