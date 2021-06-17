import java.util.Scanner;

/**
 * Chương trình nhập một số nguyên n và mảng gồm n số nguyên
 * sau đó in ra giá trị nhỏ nhất và lớn nhất của mảng trên cùng dòng, 
 * cách nhau bởi một khoảng trống. Cần giữ khung chương trình.
 * */
//import <libraries needed here>

public class FindMinMax{

    public static int findMin(int Array[]){
        //editing here
        int mn = Array[0];
        for(int x : Array) {
            mn = Math.min(mn, x);
        }
        return mn;
    }

    public static int findMax(int Array[]){
        //editing here
        int mx = Array[0];
        for(int x : Array) {
            mx = Math.max(mx, x);
        }
        return mx;
    }

    public static void main(String args[]){
        // editing here
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        System.out.println(findMin(a) + " " + findMax(a));
    }

}