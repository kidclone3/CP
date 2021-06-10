package Bai_2;

public class Car {
	private String id;
	private String name;
	private String manufacturer;
	private double hours;
	private double price;
	private double amount;
	// Constructor function
	public Car() {
		// TODO Auto-generated constructor stub
	}
	
	// Constructor function using fields
	public Car(String id, String name, String manufacturer, double hours, double price) {
		super();
		this.id = id;
		this.name = name;
		this.manufacturer = manufacturer;
		this.hours = hours;
		this.price = price;
	}

	public String getId() {
		return id;
	}

	public void setId(String id) {
		this.id = id;
	}

	public String getName() {
		return name;
	}

	public void setName(String name) {
		this.name = name;
	}

	public String getManufacturer() {
		return manufacturer;
	}

	public void setManufacturer(String manufacturer) {
		this.manufacturer = manufacturer;
	}

	public double getHours() {
		return hours;
	}

	public void setHours(double hours) {
		this.hours = hours;
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