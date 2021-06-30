public class test {
    public static void main(String[] args) {
        String tmp = "quangnv@dslab.fpt.vn";
        int a = tmp.indexOf('@'); //=> a+1
        int b = tmp.indexOf('.');
        String lab_type = tmp.substring(a+1, b);
        System.out.println(lab_type);
    }
}
