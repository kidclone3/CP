package Bai_2;

import Bai_1.Card;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Scanner;

public class CarManagement {
	
	// Hàm dựng 
	public CarManagement(){
		super();
	}
	
	// Phương thức readData() cho phép đọc dữ liệu từ tệp văn bản
	/*
	    Thứ tự nhập như sau:
	    - Nhập số lượng xe
	    - Trong vòng lặp với mỗi loại xe:
	       - Nhập 1 số nguyên c, c = 0 là ServiceCar, c = 1 là SportCar
	       - Nhập thông tin của các xe: id, name, manufacturer, hours, price, fee (Đối với ServiceCar, tax với SportCar)
	*/
	
	public ArrayList<Car> readData(String fileName) {
		ArrayList<Car> ans = new ArrayList<>();
		try
		{
			File myfile = new File(fileName);
			Scanner sc = new Scanner(myfile);

			int n = Integer.parseInt(sc.nextLine());
			for (int i = 0; i < n; i++) {
				int c = Integer.parseInt(sc.nextLine());
				String id = sc.nextLine();
				String name = sc.nextLine();
				String manu = sc.nextLine();
				double hours = Double.parseDouble(sc.nextLine());
				double price = Double.parseDouble(sc.nextLine());
				double fee = Double.parseDouble(sc.nextLine());
				if (c == 0) {
					ServiceCar tmp = new ServiceCar(id, name, manu, hours, price, fee);
					ans.add(tmp);
				}
				else {
					SportCar tmp = new SportCar(id, name, manu, hours, price, fee);
					ans.add(tmp);
				}
			}
			return ans;
		}
		catch (Exception e) {
			System.out.println("Nothing");
		}
		return null;
	}
	
	// Phương thức in danh sách thông tin liên quan các loại xe trong mảng
	public void printCars(ArrayList<Car> cars) {
		for (int i = 0; i < cars.size(); i++) {
			System.out.println(cars.get(i).toString());
		}
	}
	
	// Phương thức xuất ra danh sách những xe có tên nhà sản xuất là "manuName"
	public ArrayList<Car> findCars(ArrayList<Car> cars, String manuName){
		ArrayList<Car> ans = new ArrayList<>();
		for (Car it : cars) {
			if (it.getManufacturer().equals(manuName)) {
				ans.add(it);
			}
		}
		return ans;
	}
	
	// Phương thức xuất ra danh sách những xe giá thành tiền (amount) cao nhất thuộc loại typeOfCars
	
	public ArrayList<Car> getMaxAmount(ArrayList<Car> cars, String typeOfCars){

		ArrayList<Car> ans = new ArrayList<>();
		double mx = 0;
		for (Car it : cars) {
			if (it.getClass().getName().equals(typeOfCars)) {
				if (it.getAmount() > mx) {
					mx = it.getAmount();
					ans.clear();
					ans.add(it);
				}
				else if (it.getAmount() == mx) {
					ans.add(it);
				}
			}
		}
		return ans;
		
	}
	
	// Phướng thức sắp xếp giá thành tiền các loại xe theo thứ tự giảm dần
	public void sortByAmount(ArrayList<Car> cars){
		//Begin editable part
		int n = cars.size();
		for (int i = 0; i < n-1; i++) {
			for (int j = i+1; j < n; j++) {
				if (cars.get(i).getAmount() < cars.get(j).getAmount()) {
					Car tmp = cars.get(i);
					cars.set(i, cars.get(j));
					cars.set(j, tmp);
				}
			}
		}
	}

// Hàm main 
		public static void main(String[] args) throws FileNotFoundException {
			CarManagement carManag = new CarManagement();
			ArrayList<Car> cars = carManag.readData("src/Bai_2/data.txt");
		//	carManag.printCars(cars);
			
			for (int i = 0; i < cars.size(); i++) {
				System.out.print(cars.get(i).getAmount() + " ");
			}
			System.out.println();
			ArrayList<Car> carsList = carManag.findCars(cars,"honda");
			carManag.printCars(carsList);
			
			ArrayList<Car> carsList1 = carManag.getMaxAmount(cars, "SportCar");
			carManag.printCars(carsList1);
			
			carManag.sortByAmount(cars);
			carManag.printCars(cars);
			
		}
	}