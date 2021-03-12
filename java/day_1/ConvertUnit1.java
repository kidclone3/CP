// package java.day_1;

public class ConvertUnit1 {
   public static void main(String[] args) {
       double a = Double.parseDouble(args[0]);
       double ans = Math.round(a/0.0254*100.0)/100.0;
       System.out.println(ans);
   } 
}
