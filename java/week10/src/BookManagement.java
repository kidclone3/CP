
import java.util.ArrayList;
import java.util.Scanner;

public class BookManagement {
    /* Thứ tự nhập
        +) Số lượng các cuốn sách

        +) 1 số nguyên 0 hoặc 1 (nếu 0 là sách tham khảo, 1 là sách giáo khoa)

        +)  id (mã sách), name (tên sách), quantity (số lượng), publisher (NXB), price (giá)

        +)  status (trạng thái) với sách giáo khoa,  tax (thuế) đối với sách tham khảo.
    */
    public Book[] readData(Scanner sc) {
        int n = sc.nextInt();
        sc.nextLine();
        Book[] ans = new Book[n];
        for (int i = 0; i < n; i++) {
            int type = Integer.parseInt(sc.nextLine());
            String id, name, publisher;
            int quantity;
            double price;
            boolean status;
            double tax;
            id = sc.nextLine();
            name = sc.nextLine();
            quantity = Integer.parseInt(sc.nextLine());
            publisher = sc.nextLine();
            price = Double.parseDouble(sc.nextLine());
            if (type == 0) {
                tax = Double.parseDouble(sc.nextLine());
                Book tmp = new ReferenceBook(id, name, quantity, publisher, price, tax);
                ans[i] = tmp;
            }
            else {
                status = Boolean.parseBoolean(sc.nextLine());
                Book tmp = new TextBook(id, name, quantity, publisher, price, status);
                ans[i] = tmp;
            }
        }
        return ans;
    }
    // In thong tin các cuốn sách
    public void printBooks(Book[] books) {
        for (Book it : books) {
            System.out.println(it.toString());
        }
    }
    // Tìm các cuốn sách của nhà xuất bản publisher
    public ArrayList<Book> findBooks(Book[] books, String publisher) {
        ArrayList<Book> ans = new ArrayList<>();
        for (Book it : books) {
            if (it.getPublisher().equals(publisher)) {
                ans.add(it);
            }
        }
        return ans;
    }
    // Tính giá trị trung bình của các cuốn sách thuộc thể loại typeOfBooks
    public double computeAverage(Book[] books, String typeOfBooks) {
        int total = 0;
        double sum = 0;
        for (Book it : books) {
            if (it.getType().equals(typeOfBooks)) {
                total ++;
                sum += it.getAmount();
            }
        }
        return sum / total;
    }
    // Sắp xếp các cuốn sách tăng dần về giá tiền
    public void sortByPrice(Book[] books) {
        int n = books.length;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i+1; j < n; j++) {
                if (books[i].getPrice() > books[j].getPrice()) {
                    Book tmp;
                    tmp = books[i];
                    books[i] = books[j];
                    books[j] = tmp;
                }
            }
        }
    }

    public static void main(String[] args) {
    }
}
