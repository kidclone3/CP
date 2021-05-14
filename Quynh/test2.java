public class test2 {
    public static void inc(int &a) {
        a = 10;
    }
    public static void main (String[] args) {
        int a = 0;
        inc(a);
        System.out.println(a);
    }
}