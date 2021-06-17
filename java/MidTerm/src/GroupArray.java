import java.util.ArrayList;
import java.util.Scanner;

/**
 * chương trình nhập số nguyên n và mảng gồm n số nguyên
 * hàm/phương thức groupArray xếp số lẻ về đầu, số chẵn về cuối mảng
 * Bổ sung thêm các hàm/phương thức khác nếu cần
 * */

public class GroupArray{

    // Định nghĩa hàm/phương thức groupArray() ở đây
    // .....  groupArray(.....)
    static int[] groupArray(int[] a) {
        ArrayList<Integer> odd = new ArrayList<>();
        ArrayList<Integer> even = new ArrayList<>();
        for (int i = 0; i < a.length; i++) {
            if(a[i] % 2 == 0) {
                even.add(a[i]);
            }
            else {
                odd.add(a[i]);
            }
        }
        int[] ans = new int[a.length];
        int i = 0;
        for (Integer it : odd) {
            ans[i++] = it;
        }
        for (Integer it : even) {
            ans[i++] = it;
        }
        return ans;
    }
    public static void main(String args[]){
        // ... editing
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        a = groupArray(a);
        for (int it : a) {
            System.out.print(it + " ");
        }
    }
}