
public class ReferenceBook extends Book {
    private double tax;
    private int type;
    public ReferenceBook(String id, String name, int quantity, String publisher, double price) {

        // TODO Auto-generated constructor stub
        super(id, name, quantity, publisher, price);
        setType(2);
    }

    public ReferenceBook(String id, String name, int quantity, String publisher, double price,
                         double tax) {
        super(id, name, quantity, publisher, price);
        this.tax = tax;
        setType(2);
    }

    @Override
    public double getAmount() {
        // TODO Auto-generated method stub
        return super.getAmount() + tax;
    }

    @Override
    public String toString() {
        return "ReferenceBook [tax=" + tax + ", getId()=" + getId() + ", getName()=" + getName() + ", getQuantity()="
                + getQuantity() + ", getPublisher()=" + getPublisher() + ", getPrice()=" + getPrice() + ", getAmount()=" + getAmount() + "]";
    }
}
