// import jdk.javadoc.internal.doclets.formats.html.SourceToHTMLConverter;

// package java.day_1;

public class TripleEquals {
    public static void main(String[] args) {
        boolean check = false;
        // if (args[0].equals(args[1]) && args[0].equals(args[2])) {
        if (args[0] == args[1] && args[1] == args[2]) {
            check = true;
        }
        System.out.println(check);
    } 
}
