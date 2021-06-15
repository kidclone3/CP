public class Motorbike
{
    private String id;
    private String name;
    private String manu;
    private int quantity;
    private double price;
    private double weight;
    private String date;
    public Motorbike(String id, String name, String manu, int quantity, double price, double weight, String date) {
        this.id = id;
        this.name = name;
        this.manu = manu;
        this.quantity = quantity;
        this.price = price;
        this.weight = weight;
        this.date = date;
    }
    public void printMotorbike() {
        System.out.println(id + " " + name + " " + manu + " " + quantity + " " + price + " " + weight + " " + date);
    }
    String getManu() {
        return this.manu;
    }
    int getQuantity() {
        return this.quantity;
    }
    double getWeight() {
        return this.weight;
    }
}