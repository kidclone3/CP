import java.util.Scanner;

/**
 * Chương trình cộng 2 mảng số nguyên: 
 * Cho phép đọc số nguyên n, và 2 mảng với n phần tử nguyên
 * Tính và in ra mảng có phần tử là tổng phần tử tương ứng
 * của 2 mảng nhập vào trên một dòng, cách nhau bởi khoảng trống.
 * Yêu cầu giữ cấu trúc các hàm/phương thức đã có, có thể bổ sung nếu cần
 * */
class AddArray{

    // hàm/phương thức SumArray trả về tổng 2 mảng nguyên A, B
    // .....{.......}
    static int[] SumArray(int[] A, int[] B) {
        int[] C = new int[A.length];
        for (int i = 0; i < A.length; i++) {
            C[i] = A[i] + B[i];
        }
        return C;
    }
    // hàm/phương thức printArray để in một mảng A ra màn hình
    static void printArray(int[] A) {
        for (int i = 0; i < A.length; i++) {
            System.out.print(A[i] + " ");
        }
    }
    public static void main(String args[]){
        //editing
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        int[] b = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        for (int i = 0; i < n; i++) {
            b[i] = sc.nextInt();
        }
        int[] c = SumArray(a, b);
        printArray(c);
    }
}