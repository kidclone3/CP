package Bai_2;

public class ServiceCar extends Car{
	private double fee;

	public ServiceCar() {
		super();
		// TODO Auto-generated constructor stub
	}

	public ServiceCar(String id, String name, String manufacturer, double hours, double price, double fee) {
		super(id, name, manufacturer, hours, price);
		this.fee = fee;
	}

	public double getFee() {
		return fee;
	}

	public void setFee(double fee) {
		this.fee = fee;
	}


    // Hoàn thiện phương thức getAmount() trả về giá thành tiền trong lớp ServiceCar
	@Override
	public double getAmount() {
//		đơn giá thuê 1 giờ * số giờ thuê + phí dịch vụ

		return getPrice() * getHours() + getFee();
	}
	
	@Override
	public String toString() {
		return "ServiceCar [id=" + getId() + ", name=" + getName() + ", manufacturer=" + getManufacturer() + ", hours=" + getHours() + ", price="
				+ getPrice() + ", fee = " + fee + "]";
	}
	
}