import java.util.Scanner;

public class bai11 {
    public static String DayofWeek(int m, int d, int y) {
        int y0 = y - (14 - m)/12;
        int x = y0 + y0/4 - y0/100 + y0/400;
        int m0= m + 12 * ((14 - m)/12) - 2;
        int d0 = (d + x + 31 * m0/12) % 7;
        String ans = "";
        switch (d0) {
            case 0: {
                ans = "Thu hai";
                break;
            }
            case 1: {
                ans = "Thu ba";
                break;
            }
            case 2: {
                ans = "Thu tu";
                break;
            }
            case 3: {
                ans = "Thu nam";
                break;
            }
            case 4: {
                ans = "Thu sau";
                break;
            }
            case 5: {
                ans = "Thu bay";
                break;
            }
            case 6: {
                ans = "Chu nhat";
                break;
            }
        }
        return ans;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int d = sc.nextInt();
        int m = sc.nextInt();
        int y = sc.nextInt();
        System.out.println(DayofWeek(m, d, y));
    }
}
