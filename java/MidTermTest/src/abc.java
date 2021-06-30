import java.util.ArrayList;

public class abc {
    public static void main(String[] args) {
        int a = 5;
        Integer b = 5;
        int c = Integer.parseInt("1234");
        int[] arr = new int[5];
        arr[4] = 5;
        System.out.println(arr[4]);
        ArrayList<Integer> d = new ArrayList<>();
        d.add(b);
        d.add(7);
        d.add(10);
        d.add(1);
        d.add(11);
        d.add(11);
        d.add(11);
        d.add(11);
//        d.remove(4);
        d.set(4, 5);
        System.out.println(d.get(4));
    }
}
