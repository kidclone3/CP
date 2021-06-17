//Kiem tra mot so nguyen co là doi xung
public class Palindrome
{

    //ham kiem tra so nguyen k co la doi xung?
    //@para n kieu in
    //@return boolean
    public static boolean isPalindrome(int k)
    {
        //add code here
        int tmp = k;
        int res = 0;
        while(tmp > 0) {
            res*=10;
            res+= tmp%10;
            tmp/=10;
        }
        return res == k;
    }

    public static void main(String args[])
    {
        int n = Integer.parseInt(args[0]);
        System.out.println(isPalindrome(n));
    }

}