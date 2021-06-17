// Bài lập trình kiểm tra một số có là số siêu nguyên tố không
// kết quả in ra True nếu số là số siêu nguyên tố, False nếu số không là số siêu nguyên tố
import java.util.Scanner;

public class SuperPrime{

    public static boolean isPrime(int k){

        // ham kiem tra so nguyen to
        // return true neu k la nguyen to
        // nguoc lai return false
        if (k % 2 == 0) return k == 2;
        for (int i = 2; i * i <= k ; i++) {
            if (k % i == 0) return false;
        }
        return true;
    }

    public static boolean isSuperPrime(int n){

        // ham kiem tra so nguyen n co là sieu nguyen to 
        // tra ve TRUE neu dung/nguoc lai tra ve FALSE
        // yeu cau su dung ham isPrime o tren!
        while(n > 0) {
            if (!isPrime(n)) return false;
            n/=10;
        }
        return true;
    }

    public static void main(String args[]){

        // trong ham main chi nhap so nguyen và 
        // goi ham tren, sau do in ra ket qua
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        System.out.println(isSuperPrime(n));
    }


}