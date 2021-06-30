
public class Staff {
	private String id, name, email;
	private int age;
	double basicSalary;

	public Staff() {
		super();
	}
	
	public Staff(String id, String name, String email, int age, double basicSalary) {
		super();
		this.id = id;
		this.name = name;
		this.email = email;
		this.age = age;
		this.basicSalary = basicSalary;
		
	}

	public String toString() {
		String s = "Id: "+id+" | name: "+name+" | email: "+email+" | age: "+age+" | basicSalary: "+String.format("%.0f",basicSalary);
		
		return s;
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
	public String getEmail() {
		return email;
	}
	public void setEmail(String email) {
		this.email = email;
	}
	public int getAge() {
		return age;
	}
	public void setAge(int age) {
		this.age = age;
	}
	public double getBasicSalary() {
		return basicSalary;
	}
	public void setBasicSalary(double basicSalary) {
		this.basicSalary = basicSalary;
	}
	public double getSalary() {
		return basicSalary;
	}
	
}
