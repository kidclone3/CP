import java.util.ArrayList;
public class Main{
    public static void main (String []args){
	ArrayList<Shape> shapes = new ArrayList<Shape>();
	shapes.add(new Square(5));
	shapes.add(new Rectangle(2,4));
	System.out.println(shapes.get(0).getArea());
	System.out.println(shapes.get(1).getArea());
    }
}
