public interface Shape {
    double getPerimeter(); // tính chu vi
    double getArea(); // tính diện tích

    default int compareTo(Shape shape){
        if(getArea() > shape.getArea()) {
            return 1;
        }
        if(getArea() == shape.getArea()) {
            return 0;
        }
        return -1;
    }
}