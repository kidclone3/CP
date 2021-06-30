import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class StaffManagement {
	
	public ArrayList<Staff> readData(String fileName){
		
	
		return null;
	}
	
	public void printInforStaffs(ArrayList <Staff> staffs) {
		
	}
	
	public void sortBySalary(ArrayList <Staff> staffs) {
	
	}
	
	public ArrayList <Staff> filterDep_byOT(ArrayList <Staff> staffs,  String lab){
		
		return null;
	}
	
	public ArrayList <Staff> filterTest_bySalary(ArrayList <Staff> staffs) {
			
		return null;
	}
	
	
	public static void main(String[] args) {
		
		StaffManagement stm = new StaffManagement();
		ArrayList<Staff> staffs = stm.readData("staff.txt");
		System.out.println(" Danh sách nhân viên: ");
		stm.printInforStaffs(staffs);
		
		System.out.println("Danh sách nhân viên sau khi sắp xếp theo lương: ");
		stm.sortBySalary(staffs);
		stm.printInforStaffs(staffs);
		
		System.out.println("Danh sách nhân viên Phòng khoa học dữ liệu làm vượt giờ nhiều hơn số giờ trung bình");
		ArrayList<Staff> ot_staffs = stm.filterDep_byOT(staffs, "Phòng khoa học dữ liệu");
		stm.printInforStaffs(ot_staffs);
		
		System.out.println("Danh sách nhân viên kiểm thử có mức lương cao hơn mức lương trung bình của lập trình viên");
		ArrayList<Staff> test_staffs = stm.filterTest_bySalary(staffs);
		stm.printInforStaffs(test_staffs);
		
	}
	
	
}
