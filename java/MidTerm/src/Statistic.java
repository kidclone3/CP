import java.util.Scanner;
public class Statistic{

    // Hoàn thiện phương thức readArray thực hiện nhập và trả lại mảng a theo hướng dẫn sau:
    // 1. Nhập vào kích thước mảng là số nguyên dương n
    // 2. Khai báo mảng số nguyên a có kích thước n
    // 3. Nhập vào n số nguyên cho mảng a
    // 4. trả lại kết quả của hàm là mảng a (return a)
    public static int[] readArray(Scanner reader)
    {
        int n = reader.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = reader.nextInt();
        }
        return a;
    }
    // Hoàn thiện phương thức mean, thực hiện tính kỳ vọng (trung bình) của mảng array
    // 1. Tính tổng các phần tử trong mảng (sum)
    // 2. Tính giá trị trung bình bằng sum chia cho số phần tử, chú ý giá trị trung bình là số thực
    public static double mean(int[] array)
    {
        double sum = 0.0;
        for (int it : array) {
            sum += it;
        }
        return sum/array.length;
    }
    // Hoàn thiện phương thức variance thực hiện tính phương sai của mảng a
    // 1. Tính tổng bình phương của (từng giá trị trong mảng array - mean(array),
    //    chú ý nên đặt 1 biến lưu giá trị mean(array) để tránh phải tính lại nhiều lần.
    // 2. Chia tổng này cho số phần tử trong mảng array, chú ý phương sai là số thực
    public static double variance(int[] array)
    {
        double mid = mean(array);
        double var = 0.0;
        for (int it : array) {
            var += Math.abs(it - mid) * Math.abs(it - mid);
        }
        return var / array.length;
    }

    // Hàm main được viết sẵn, sinh viên không cần viết, chỉnh sửa, 
    // tuy nhiên chương trình chỉ chạy đúng nếu các phương thức trên sinh viên làm đúng
    public static void main(String[] args){
        Scanner reader = new Scanner(System.in);
        int[] array = readArray(reader);
        System.out.printf("%.3f\n",mean(array));
        System.out.printf("%.3f",variance(array));
    }


}