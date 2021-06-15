import java.util.function.DoubleBinaryOperator;

public class Computer implements Comparable<Computer> {

    // khai báo các thuộc tính của một computer
    // tạo tất cả các hàm dựng (có đối và không đối)
    // xây dựng các hàm getter, setter phù hợp với các thuộc tính
    //
    private String name;
    private String manu;
    private int year;
    private String detail;
    private double price;
    public Computer() {
    }

    public Computer(String name, String manu, int year, String detail, double price) {
        this.name = name;
        this.manu = manu;
        this.year = year;
        this.detail = detail;
        this.price = price;
    }
    String getName() {
        return this.name;
    }
    String getManu() {
        return this.manu;
    }
    String getYear() {
        return Integer.toString(this.year);
    }
    String getDetail() {
        return this.detail;
    }
    double getPrice() {
        return this.price;
    }
    // Hàm trả về một chuỗi thông tin của một máy tính, mỗi thuộc tính cách nhau một dấu cách
    @Override
    public String toString() {
        return getName() + " " + getManu() + " " + getYear() + " " + getDetail() + " " + Double.toString(getPrice());
    }
    @Override
    public int compareTo(Computer cmp) {
        return -Double.compare(this.price, ((Computer) cmp).price);
    }
}