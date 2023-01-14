
import java.util.Scanner;

import javax.swing.text.StyledEditorKit;

public class cb03 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a, b;
        a = sc.nextInt();
        b = sc.nextInt();
        System.out.println(a+b);
        System.out.println(a-b);
        System.out.println(a*b);
        double f;
        if (b==0) {
            System.out.println("INF");
            return;
        }
        else f = a/(b*1.0);
        System.out.printf("%.2f\n",f);
    }
}