public class bai7 {
    public static void modifyArray(int array[]){
        for(int number:array)
            number *= 2.0;
//        => ko thay đổi phần tử.
        /* so với đoạn mã gốc:
        for (int i = 0; i<array.length; i++)
        array[i] *= 2.0;
        *******/
    }

    public static void main(String[] args) {
        int a[] = {1, 2, 3, 4, 5};
        modifyArray(a);
        for (int it : a) {
            System.out.printf("%d ", it);
        }
//        bai8: vòng lặp thực hiện việc đếm số phần tử a[i] xuất hiện trong dãy a.
    }

}
