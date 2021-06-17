import java.util.Scanner;

public class NameProperty {
    static String nameProperty(String name) {
//        name = name.trim();
        name = name.trim().replaceAll("\\s+", " ");
        //        regex, s = space;
        char[] char_name= name.toCharArray();
        for (int i = 0; i < name.length(); i++) {
            if (i == 0 || char_name[i-1] == ' ') {
                char_name[i] = Character.toUpperCase(char_name[i]);
            }
            else {
                char_name[i] = Character.toLowerCase(char_name[i]);
            }
        }
        return String.valueOf(char_name);
//        System.out.println(name);
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String name = sc.nextLine();
        name = nameProperty(name);
        System.out.println(name);
    }
}
