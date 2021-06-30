import java.awt.image.AreaAveragingScaleFilter;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.*;

public class StaffManagement {
	
	public ArrayList<Staff> readData(String fileName) {
		File file = new File(fileName);
		try {
			Scanner sc = new Scanner(file);
			ArrayList<Staff> ans = new ArrayList<>();
			int t = Integer.parseInt(sc.nextLine());
			while(t-- > 0) {
				int number = Integer.parseInt(sc.nextLine());
				String id = sc.nextLine();
				String name = sc.nextLine();
				int age = Integer.parseInt(sc.nextLine());
				String email = sc.nextLine();
				double basicSalary = Double.parseDouble(sc.nextLine());
				if (number == 0) {
					int errs = Integer.parseInt(sc.nextLine());
					Tester tmp = new Tester(id, name, email, age, basicSalary, errs);
					ans.add(tmp);
				}
				else {
					double hours = Double.parseDouble(sc.nextLine());
					Developer tmp = new Developer(id, name, email, age, basicSalary, hours);
					ans.add(tmp);
				}
			}
			return ans;
		}
		catch (Exception e) {
			System.out.println("Đ' có file");

		}
		return null;
	}
	
	public void printInforStaffs(ArrayList <Staff> staffs) {
		try {
			for(Staff it : staffs) {
				System.out.println(it.toString());
			}
		}
		catch (Exception e) {

		}
	}
	
	public void sortBySalary(ArrayList <Staff> staffs) {
		Collections.sort(staffs, new Comparator<Staff>() {
			@Override
			public int compare(Staff a, Staff b) {
				return Double.compare(a.getSalary(), b.getSalary());
			}
		});
	}
	
	public ArrayList <Staff> filterDep_byOT(ArrayList <Staff> staffs,  String lab){
//		Dau` tien la` tinh so' h trung binh`
		double sum = 0.0;
		ArrayList<Staff> tmp = new ArrayList<>();
		for (Staff it : staffs) {
			if (it.getClass().getName().equals("Developer")) {
				if (((Developer)it).getLab().equals(lab)) {
					sum += ((Developer)it).getHours_OT();
					tmp.add(it);
				}
			}
		}
		sum /= tmp.size();
		System.out.println(sum);
		ArrayList<Staff> ans = new ArrayList<>();
		for(Staff it : tmp) {
			if (((Developer)it).getHours_OT() > sum) {
				ans.add(it);
			}
		}
		return ans;
	}
	
	public ArrayList <Staff> filterTest_bySalary(ArrayList <Staff> staffs) {
			ArrayList<Staff> tester = new ArrayList<>();
			double sum = 0.0;
			for(Staff it : staffs) {
				if (it.getClass().getName().equals("Developer")) {
					sum += it.getSalary();
				}
				else {
					tester.add(it);
				}
			}
			sum /= staffs.size() - tester.size();
			ArrayList<Staff> ans = new ArrayList<>();
			for(Staff it : tester) {
				if (it.getSalary() > sum) {
					ans.add(it);
				}
			}
			Collections.sort(ans,
				new Comparator<Staff>() {
					@Override
					public int compare(Staff a, Staff b) {
						return Double.compare(b.getSalary(), a.getSalary());
					}
				});
			return ans;
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
