
import java.util.Arrays;
import java.util.Scanner;

public class ComputerTest {

    private Computer computers[];
    private int n;

    // Hàm nhập vào số n và một mảng gồm thông tin của n máy tính
    public void input(Scanner scan)
    {
        n = scan.nextInt();
        Computer[] cpu = new Computer[n];
        scan.nextLine();
        for (int i = 0; i < n; i++) {
            String name = scan.nextLine();
            String manu = scan.nextLine();
            int year = Integer.parseInt(scan.nextLine());
            String detail = scan.nextLine();
            double price = Double.parseDouble(scan.nextLine());
            Computer tmp = new Computer(name, manu, year, detail, price);
            cpu[i] = tmp;
        }
        computers = cpu;
    }

    // in ra các máy tính, mỗi thông tin của một máy tính trên một dòng
    public void output()
    {
        for (Computer it : computers) {
            System.out.println(it.toString());
        }
    }

    // Trả về giá trung bình của các máy tính
    public double getAvgPrice()
    {
        double sum = 0;
        for (int i = 0; i < n; i++) {
            sum += computers[i].getPrice();
        }
        return sum / n;
    }

    // In ra các máy tính có giá cao nhất
    public void getMaxPrice()
    {
        double mx = computers[0].getPrice();
        for (int i = 1; i < n; i++) {
            mx = Math.max(mx, computers[i].getPrice());
        }
        for (Computer it : computers) {
            if (Double.compare(it.getPrice(), mx) == 0) {
                System.out.println(it.toString());
            }
        }
    }

    // In ra các máy tính có nhà sản xuất là Dell
    public void getDell()
    {
        for(Computer it : computers) {
            if (it.getManu().equals("Dell")) {
                System.out.println(it.toString());
            }
        }
    }

    // Sắp xếp các máy tính theo chiều giảm dần của giá, và in ra mảng sau khi sắp xếp
    public void sort()
    {
        Arrays.sort(computers);
        for(Computer it : computers) {
            System.out.println(it.toString());
        }
    }

    public static void main(String[] args) {

    }

}