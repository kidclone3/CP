package Bai_1;

public class Card {
    String id;
    int year;
    double days;
    double price;
    double amount;
    public Card(String id, int year, double days, double price) {
        super();
        this.id = id;
        this.year = year;
        this.days = days;
        this.price = price;
    }
    public String getId() {
        return id;
    }
    public void setId(String id) {
        this.id = id;
    }
    public int getYear() {
        return year;
    }
    public void setYear(int year) {
        this.year = year;
    }
    public double getDays() {
        return days;
    }
    public void setDays(double days) {
        this.days = days;
    }
    public double getPrice() {
        return price;
    }
    public void setPrice(double price) {
        this.price = price;
    }
    public double getAmount() {
        return amount;
    }
    public void setAmount(double amount) {
        this.amount = amount;
    }

}