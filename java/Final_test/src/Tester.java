public class Tester extends Staff{
	
	private int no_errors;

	public Tester() {
		super();
		// TODO Auto-generated constructor stub
	}

	public Tester(String id, String name, String email, int age, double basicSalary, int no_errors) {
		super(id, name, email, age, basicSalary);
		// TODO Auto-generated constructor stub
		this.no_errors = no_errors;
	}

	public int getNo_errors() {
		return no_errors;
	}

	public void setNo_errors(int no_errors) {
		this.no_errors = no_errors;
	}
	
	// Sửa lại kết quả trả về để có xâu ký tự như trong yêu cầu của đề bài
	public String toString() {
		return super.toString()+" | staffType: "+this.getClass().getName()+" | no_errors: " +no_errors+" | salary: "+String.format("%.0f",getSalary());
	}
	
	// SINH VIÊN HOÀN THIỆN PHƯƠNG THỨC getSalary() dưới đây:
	public double getSalary() {
		// Lương của nhân viên kiểm thử = lương cơ bản + số lỗi phát hiện được*10.000
		return getBasicSalary() + no_errors*10000;
	}
	
	

}