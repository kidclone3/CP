
import java.util.ArrayList;
import java.util.Scanner;
public class ShapeTest{

    public static ArrayList<Shape> readData()
    {
        ArrayList<Shape> shapes = new ArrayList<Shape>();
        // Đọc dữ liệu vào danh sách shapes
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        sc.nextLine();
        for (int i = 0; i < n; i++) {
            int b, c;
            String s = sc.nextLine();
            String[] inp = s.split(" ");
            b = Integer.parseInt(inp[1]);
            if (inp[0].equals("r")) {
                c = Integer.parseInt(inp[2]);
                Rectangle tmp = new Rectangle(b, c);
                shapes.add(tmp);
            }
            else {
                if (inp[0].equals("c")) {
                    Circle tmp = new Circle(b);
                    shapes.add(tmp);
                }
                else {
                    Square tmp = new Square(b);
                    shapes.add(tmp);
                }
            }
        }
        return shapes;
    }


    public static Circle getMaxCircle(ArrayList<Shape> shapes)
    {
        Circle ans = new Circle();
        double mx = 0;
        for (Shape it : shapes) {
            if (it.getClass().getName().equals("Circle")) {
                if (it.getArea() >= mx) {
                    mx = it.getArea();
                    ans = (Circle) it;
                }
            }
        }
        return ans;
    }


    public static Square getMaxSquare(ArrayList<Shape> shapes)
    {
        Square ans = new Square();
        double mx = 0;
        for (Shape it : shapes) {
            if (it.getClass().getName().equals("Square")) {
                if (it.getArea() >= mx) {
                    mx = it.getArea();
                    ans = (Square) it;
                }
            }
        }
        return ans;
    }

    public static Rectangle getMaxRectangle(ArrayList<Shape> shapes)
    {
        Rectangle ans = new Rectangle();
        double mx = 0;
        for (Shape it : shapes) {
            if (it.getClass().getName().equals("Rectangle")) {
                if (it.getArea() >= mx) {
                    mx = it.getArea();
                    ans = (Rectangle) it;
                }
            }
        }
        return ans;
    }
    public static void main(String[] args){
        ArrayList<Shape> shapes = readData();
        sort(shapes);
        Circle c = getMaxCircle(shapes);
        Square s = getMaxSquare(shapes);
        Rectangle r = getMaxRectangle(shapes);
        if(c!=null)
        {
            System.out.printf("Circle %.2f\n",c.getArea());
        }
        else
        {
            System.out.println("Circle =  null");
        }
        if(s!=null)
        {
            System.out.printf("Square %.2f\n",s.getArea());
        }
        else
        {
            System.out.println("Square =  null");
        }

        if(r!=null)
        {
            System.out.printf("Rectangle %.2f\n",r.getArea());
        }
        else
        {
            System.out.println("Rectangle =  null");
        }

    }

    public static void sort(ArrayList<Shape> shapes){
        int n = shapes.size();

        for (int i = 0; i < n - 1; i++)
            for (int j = i+1; j < n; j++) {
                if((shapes.get(i)).compareTo(shapes.get(j)) > 0){
                    Shape temp = shapes.get(i);
                    shapes.set(i, shapes.get(j));
                    shapes.set(j, temp);
                }
            }
    }
}
