import java.util.Scanner;

public class bit {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int x = 0;
        sc.nextLine();
        for (int i = 0; i<n; ++i) {
            String s = sc.nextLine();
            if (s.equals("++X") || s.equals("X++")) {
                x++;
            }
            else {
                x--;
            }
        }
        System.out.println(x);
    }
}
