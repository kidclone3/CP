import java.util.Scanner;

class Substring {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s, t;
        s = sc.nextLine();
        t = sc.nextLine();
        sc.close();
        // System.out.println(s + " "+ t);
        int last = 0;
        for (int i = 0; i < t.length(); ++i) {
            int j = 0;
            // System.out.println(t.charAt(i));
            for (j = last; j <s.length(); ++j) {
                if (t.charAt(i) == s.charAt(j)) {
                    last = j+1;
                    break;
                }
                // System.out.println(j);
            }
            if (j == s.length()) {
                System.out.print("N");
                return;
            }
        }
        System.out.print("Y");
    }
}