import java.util.Scanner;

// package java.day_2;

class test {
    public static void main(String[] args) {
        // System.out.println(Math.sqrt(2) * Math.sqrt(2) == 2);
        // int A = 27 * “three”; => Loi, "three" ko tuong thich voi kieu du lieu

        // Double x;
        // System.out.println(x); // Loi: khoi tao bien x nhung chua co gia' tri

        // Scope 2:
        // {
        //     double r;
        //     r = 3.14;
        // }
        // System.out.println(r); => Loi, vi ko nhan bien r (r chi la bien dia phuong trong {})
        
        // Bai 7: (done)
        // System.out.println(10/3); => = 3, vi no la int/int => kqua la int

        // Bai 8: (done)
        // int x = 5;//spoce of x: whole function main
        // int y = 72;//spoce of y: only in this block
        // {
        //     x = 6; // Error: variable x is already defined
        //     System.out.println("x = "+x + "y="+y);
        // }
        // System.out.println("x = "+x + "y="+y);
        
        // Bai 9:
        int testGrade;
        Scanner sc = new Scanner(System.in);
        testGrade = sc.nextInt();
        // boolean isA = (80 <= testGrade <= 100); => sai, vi ko ko bieu thuc logic nhu the
        boolean isA = (80 <= testGrade && testGrade <= 100); // => sua.
        System.out.println(isA);

    }
}