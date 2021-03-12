// package java.day_1;

// import org.jcp.xml.dsig.internal.dom.DOMBase64Transform;

public class AverageThree {
    public static void main(String[] args) {
        double a, b, c;
        a = Double.parseDouble(args[0]);
        b = Double.parseDouble(args[1]);
        c = Double.parseDouble(args[2]);
        double mid = (a+b+c) / 3.0;
        System.out.println(mid);
    } 
}
