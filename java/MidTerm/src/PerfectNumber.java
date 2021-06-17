import java.util.Scanner;
//Viet chuong trinh kiem tra mot so nguyen duong n nhap tu ban phim co phai la so hoan hao hay khong
class PerfectNumber
{
    public static boolean isPerfect(int n)
    {
        // begin edit
        int sum = 1;
        for (int i = 2; i * i <= n ; i++) {
            if (n % i == 0) {
                if (i == n/i) sum += i;
                else sum += i + n/i;
            }
        }
        return sum == n;
        //end edit

    }
    public static void main(String []args)
    {

    }

}