// package java.day_1;

public class Distance {
    public static void main(String[] args) {
        double[] a = new double[5];
        for(int i= 0; i< 4; ++i) {
            a[i] = Double.parseDouble(args[i]);
        }
        double ans = Math.sqrt(Math.pow((a[0]-a[2]),2) + Math.pow((a[1]-a[3]),2));
        ans = Math.round((ans*100.0)) / 100.0;
        System.out.println(ans);
    }
}
