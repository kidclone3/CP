import java.util.Scanner;

class sum {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int sum = 0;
        sc.nextLine();
        for (int i = 0; i < n; ++i) {
            String tmp = sc.nextLine();
            switch(tmp) {
                case "one":
                    sum+=1;
                    break;
                case "two":
                    sum+=2;
                    break;
                case "three":
                    sum+=3;
                    break;
                case "four":
                    sum+=4;
                    break;
                case "five":
                    sum+=5;
                    break;
                case "six":
                    sum+=6;
                    break;
                case "seven":
                    sum+=7;
                    break;
                case "eight":
                    sum+=8;
                    break;
                case "nine":
                    sum+=9;
                    break;
            }
        }
        System.out.println(sum);
        sc.close();
    }
}