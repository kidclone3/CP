import java.util.Scanner;

public class exercise1_2_3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        String s = String.valueOf(Math.PI);
        System.out.println(s.length());
        for (int i = 0; i < n + 2; i++) {
            System.out.print(s.charAt(i));
        }
        System.out.println();
    }
}
