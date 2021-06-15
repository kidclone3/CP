public class Circle implements Shape{
    private double r; // bán kính hình tròn

    public Circle(){
    }
    public Circle(double r){
        this.r = r;
    }

    public void setRadius(double r){
        this.r = r;
    }

    public double getRadius(){
        return r;
    }

    public double getDiameter(){
        return 2*r;
    }


    // Cài đặt các phương thức của giao diện Shape
    public double getPerimeter(){
        return 2*r*Math.PI;
    }

    public double getArea(){
        return r*r*Math.PI;
    }

    // Phương thức riêng tính diện tích hình vuông ngoại tiếp hình tròn
    public double getFrameArea(){
        return 4*r*r;
    }

    // Ghi đè phương thức default của giao diện Shape
    public int compareTo(Shape shape){
        if(shape.getClass().getName().equals("Circle")){
            double radius = ((Circle)shape).getRadius();
            if(r > radius)
                return 1;
            else if(r == radius)
                return 0;
            else
                return -1;
        }

        double frameArea = getFrameArea();
        if(frameArea > shape.getArea()) {
            return 1;
        }
        else if(frameArea == shape.getArea()) {
            return 0;
        }
        return -1;
    }

}