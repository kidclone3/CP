public class ThreeSort {
    public static void main(String[] args) {
        int a, b, c;
        a = Integer.parseInt(args[0]);   
        b = Integer.parseInt(args[1]);   
        c = Integer.parseInt(args[2]);   
        int min, max, mid;
        min = Math.min(Math.min(a,b), c);
        max = Math.max(Math.max(a,b), c);
        mid = a+b+c - min - max;
        // System.out.print(min + " " + mid + " " + max + "\n");
        System.out.printf("%d %d %d\n", min, mid, max);
    }
}