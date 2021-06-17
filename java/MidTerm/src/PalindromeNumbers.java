import java.util.Scanner;
//in ra cac so doi xung giua M và N
public class PalindromeNumbers{

    //ham kiem tra so nguyen k co la doi xung?
    //@para n kieu in
    //@return boolean
    public static boolean isPalindrome(int k)
    {
        // Noi dung ham o day
        int tmp = k;
        int res = 0;
        while(tmp>0) {
            res *= 10;
            res += tmp % 10;
            tmp/=10;
        }
        return res == k;
    }

    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int m = sc.nextInt();
        int n = sc.nextInt();
        int tmp = m + n;
        m = Math.min(m, n);
        n = tmp - m;
        for (int i = m; i <= n; i++) {
            if (isPalindrome(i)) {
                System.out.print(i + " ");
            }
        }
    }

}
