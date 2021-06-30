
public class Developer extends Staff{
	
	
	private double hours_OT;
	public Developer() {
		super();
		// TODO Auto-generated constructor stub
	}
	
	
	public Developer(String id, String name, String email, int age, double basicSalary, double hours_OT) {
		super(id, name, email, age, basicSalary);
		// TODO Auto-generated constructor stub
	
		this.hours_OT = hours_OT;
	}
	
	
	
	public double getHours_OT() {
		return hours_OT;
	}


	public void setHours_OT(double hours_OT) {
		this.hours_OT = hours_OT;
	}


	public String toString() {
		return super.toString()+" | staffType: "+this.getClass().getName()+" | hours_OT: "+hours_OT+" | salary: "+String.format("%.0f",getSalary());
	}
	
	// SINH VIÊN HOÀN THIỆN PHƯƠNG THỨC getLab() dưới đây:
	
	public String getLab() {
		
		/*Phòng của mỗi nhân viên được xác định dựa vào việc phân tích tên miền trong địa chỉ email của lập trình viên. 
		Ví dụ: 
			-	Địa chỉ email quangnv@dslab.fpt.vn: nhân viên ở Phòng khoa học dữ liệu
			-	Địa chỉ emal: hoangnv@smlab.fpt.vn: nhân viên ở Phòng quản trị hệ thống
		 */
		
		return "";
	}
	
	// SINH VIÊN HOÀN THIỆN PHƯƠNG THỨC getSalary() dưới đây:
	public double getSalary() {
		// Lương của lập trình viên = lương cơ bản + số giờ làm thêm * 200.000
		
	
		
		return 0;
	}
	
	

}
