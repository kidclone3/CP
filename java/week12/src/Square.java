public class Square implements Shape{
    private double length; // cạnh hình vuông
    public Square(){
    }
    public Square(double a){
        length = a;
    }

    public double getLength(){
        return length;
    }
    public void setLength(double a){
        length = a;
    }

    // Cài đặt các phương thức của giao diện Shape
    public double getPerimeter(){
        return 4*length;
    }

    public double getArea(){
        return length*length;
    }


}