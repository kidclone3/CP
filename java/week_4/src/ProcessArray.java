import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class ProcessArray {
    public static int countValue(double x, double Array[]) {
        int ans = 0;
        for (double it : Array) {
            if ((it - x) < 1e-9) {
                ans++;
            }
        }
        return ans;
    }
    public static double minArray(double Array[]){
        double min = Array[0];
        for (double it : Array) {
            min = Math.min(it, min);
        }
        return min;
    }
    public static double maxArray(double Array[]){
        double max = Array[0];
        for (double it : Array) {
            max = Math.min(it, max);
        }
        return max;
    }
    public static int[] indexValue(double x, double Array[]) {
        List<Integer> ans = new ArrayList<Integer>();
        for (int i = 0; i < Array.length ; i++) {
            if (Array[i] == x) {
                ans.add(i);
            }
        }
        int [] res = new int[ans.size()];
        for (int i = 0; i < ans.size(); ++i) {
            res[i] = ans.get(i);
        }
        return res;
    }
    public static double[] sortIncArray(double arr[]) {
        Arrays.sort(arr);
        return arr;
    }
    public static void sortDecArray(double arr[]) {
        Arrays.sort(arr);
        double[] tmp = new double[arr.length];
        for (int i = 0, j = arr.length-1; j >= 0; j--, i++) {
            tmp[i] = arr[j];
        }
//        arr = tmp;
        for (int i = 0; i < arr.length; i++) {
            arr[i] = tmp[i];
        }
    }

    public static void main(String[] args) throws FileNotFoundException {
        File file = new File("src/input.txt");
//       Vì dùng ideaj nên phải để tên file là src/input.txt
        Scanner sc = new Scanner(file);
        double x = sc.nextDouble();
        int n = sc.nextInt();
        double a[] = new double[n];
        for (int i = 0; i < n; ++i) {
            a[i] = sc.nextDouble();
        }
        System.out.println(countValue(x, a));
//        in ra min max của hàm;
        sortDecArray(a);
//        Arrays.sort(a);
        for (double it : a) {
            System.out.printf("%f ", it);
        }
//        System.out.println("Max: " + maxArray(a));
//        System.out.println("Min: " + minArray(a));
    }
}
