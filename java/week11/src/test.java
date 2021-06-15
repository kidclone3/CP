public class test {
    public static String name = "BKD";
    static int cnt1 = 0;
    int cnt2 = 0;
    void inc() {
        cnt2++;
        cnt1++;
    }
    public static String abc() {
        name = "KID";
        return name;
    }
    public static void main(String[] args) {
        String a = "aabb";
        String b = "aac";
        if (a.compareTo(b) > 0) {
            System.out.println("a is greater than b");
        }
        else {
            System.out.println("a is smaller than b");
        }
    }
}
