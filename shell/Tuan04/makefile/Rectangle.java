public class Rectangle implements Shape{
    private double a, b;
    public Rectangle (double a, double b){
	this.a = a;
	this.b = b;
    }
    public double getArea()
    { return a*b;
    }
}
