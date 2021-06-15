/** Class EduCenter: 
 * Lớp dùng để gọi thực hiện và kiểm thử các lớp đã xây dựng trước đó. 
 * Cần hoàn thiện các phương thức chưa đầy đủ nhưng phải giữ nguyên mẫu
 * phương thức (khai báo, đối số, kiểu trả về). Có thể thay đổi giá trị 
 * sau lệnh return cuối các phương thức nhưng cần giữ nguyên kiểu trả về. 
 * Có thể bổ sung phương thức nếu cần, nhưng phải giữ lại đầy đủ các phương thức đã được khai báo sẵn
 * */


import javax.xml.crypto.Data;
import java.util.Scanner;
import java.util.ArrayList;

public class EduCenter{
    public static int currentYear = 2020;
    public static double baseAmount;

    public static Person[] readData(Scanner scan){
        // Có thể sửa giá trị trả về của lệnh return
        // nhưng không thay đổi kiểu trả về!

        try{
            // bổ sung mã lệnh ở đây! Có thể sửa giá trị trả về của lệnh return
            // nhưng không thay đổi kiểu trả về!
            // Thứ tự dữ liệu nhập: Đọc và thực hiện đúng theo yêu cầu như trong mô tả
            int n = Integer.parseInt(scan.nextLine());
            Person[] result = new Person[n];
            for (int i = 0; i < n; i++) {
                String code = scan.nextLine();
                String name = scan.nextLine();
                int dd, yy, mm;
                dd = scan.nextInt();
                mm = scan.nextInt();
                yy = scan.nextInt();
                scan.nextLine();
                Date birthday = new Date(yy, mm, dd);
                boolean gender = Boolean.parseBoolean(scan.nextLine());
                String mail = scan.nextLine();
                String address = scan.nextLine();
                if (code.charAt(0) == '1') {
                    double score = Double.parseDouble(scan.nextLine());
                    String major = scan.nextLine();
                    Student tmp = new Student(code, mail, major, score, name, birthday, gender, address);
                    result[i] = tmp;
                }
                else {
                    String dept = scan.nextLine();
                    double salary = Double.parseDouble(scan.nextLine());
                    int re_mm, re_dd, re_yy;
                    re_dd = scan.nextInt();
                    re_mm = scan.nextInt();
                    re_yy = scan.nextInt();
                    scan.nextLine();
                    Date recruit = new Date(re_yy, re_mm, re_dd);
                    Staff tmp = new Staff(code, mail, dept, salary, recruit, name, birthday, gender, address);
                    result[i] = tmp;
                }
            }
            return result;
        } catch(ArithmeticException ArtmExcp){
            System.out.print(ArtmExcp.getMessage() );
            return null;
        } catch(Exception Excp){
            System.out.println("Data types mismatch!");
            return null;
        }
        // Có thể sửa giá trị trả về của lệnh return
        // nhưng không thay đổi kiểu trả về!


    }

    public static ArrayList<Person> listOfStaff(Person[] listPerson){

        ArrayList<Person> results = new ArrayList<Person>();
        // bổ sung mã lệnh ở đây! Có thể sửa giá trị trả về của lệnh return
        // nhưng không thay đổi kiểu trả về!
        for (int i = 0; i < listPerson.length; i++) {
            if (listPerson[i].getCode().charAt(0) == '0') {
                results.add(listPerson[i]);
            }
        }
        if ( results.size() > 0)
            return results;
        else
            return null;
    }

    public static void sortStaffBySalary(ArrayList<Person> listStaff){
        Staff tmp;
        int n = listStaff.size();
        Staff staffI, staffJ;
        for (int i = 0; i < n-1; i ++)
            for(int j = i + 1; j < n; j++){
                staffI = (Staff)listStaff.get(i);
                staffJ = (Staff)listStaff.get(j);
                if(staffI.getSalary() > staffJ.getSalary()){
                    tmp = (Staff)listStaff.get(i);
                    listStaff.set(i, listStaff.get(j) );
                    listStaff.set(j, tmp);
                }
            }
    }

    public static void sortStudentByScore(ArrayList<Person> listStudent){
        // bổ sung mã lệnh ở đây! Không thay đổi khai báo phương thức!
        // Tham khảo phương thức sortStaffBySalary
        Student tmp;
        int n = listStudent.size();
        Student staffI, staffJ;
        for (int i = 0; i < n-1; i ++)
            for(int j = i + 1; j < n; j++){
                staffI = (Student) listStudent.get(i);
                staffJ = (Student) listStudent.get(j);
                if(staffI.getScore() > staffJ.getScore()){
                    tmp = (Student) listStudent.get(i);
                    listStudent.set(i, listStudent.get(j) );
                    listStudent.set(j, tmp);
                }
            }
    }

    public static ArrayList<Person> listOfStudent(Person[] listPerson){

        ArrayList<Person> results = new ArrayList<Person>();

        // bổ sung mã lệnh ở đây! Có thể sửa giá trị trả về của lệnh return
        // nhưng không thay đổi kiểu trả về!
        for (int i = 0; i < listPerson.length; i++) {
            if (listPerson[i].getCode().charAt(0) == '1') {
                results.add(listPerson[i]);
            }
        }
        if(results.size() > 0)
            return results;
        else
            return null;
    }

    public static Person searchByCode(Person[] listPerson, String code){

        // bổ sung mã lệnh ở đây! Có thể sửa giá trị trả về của lệnh return
        // nhưng không thay đổi kiểu trả về!
        for (Person it : listPerson) {
            if (it.getCode().equals(code)) {
                return it;
            }
        }
        return null;
    }

    // Phương thức theo yêu cầu ở mục 4.2 trong mô tả
    public static void displayList(Person[] listPerson){
        if(listPerson != null){

            // bổ sung mã lệnh ở đây!
            for (Person it : listPerson) {
                System.out.println(it.toString());
            }

        } else{
            System.out.println("No any person in this list!");
        }
    }

    // Phương thức theo yêu cầu ở mục 4.3 trong mô tả
    public static void displayList(ArrayList<Person>  listPerson){
        // Bổ sung mã lệnh để phương thức này có thể thông tin ra màn hình đúng theo mẫu
        // cả trường hợp Student và Staff
        int n = listPerson.size();
        if(n > 0){

            for (int i = 0; i < n; i ++){
                if(listPerson.get(i).getClass().getSimpleName().equals("Staff")){
                    Staff staff = (Staff) listPerson.get(i);
                    /* Đặt staff = (Staff)(đối tượng thứ i). Bổ sung lệnh để in ra xâu ký tự theo mẫu sau: */
                    System.out.println(staff.toString() + " Income:" + String.valueOf(staff.getRealEarnings(currentYear)));

                }else{
                    Student student = (Student) listPerson.get(i);
                    /* Đặt student = (Student)(đối tượng thứ i). Bổ sung lệnh để in ra xâu ký tự theo mẫu sau: */
                    System.out.println(student.toString() + " Total Fees:" + String.valueOf(student.getPayment(baseAmount)));
                }
            }
        } else{
            System.out.println("No any person in this list!");
        }
    }


    public static void sortByLastName(Person[] listPerson){
        // Bổ sung mã lệnh để phương thức này có thể sắp xếp mảng theo thứ tự tăng dần 
        // của phần tên LastName (từ cuối cùng của tên đầy đủ) các đối tượng Person
        // Dùng phương thức lớp String: str1.compareTo(String str2) để so hai xâu str1 và str2.
        int n = listPerson.length;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i+1; j < n; j++) {
                String arri[] = listPerson[i].getName().split(" ");
                String arrj[] = listPerson[j].getName().split(" ");
                String lastNamei = arri[arri.length - 1];
                String lastNamej = arrj[arrj.length - 1];
                if (lastNamei.compareTo(lastNamej) > 0) {
                    Person tmp;
                    tmp = listPerson[i];
                    listPerson[i] = listPerson[j];
                    listPerson[j] = tmp;
                }

            }
        }
    }

    public static ArrayList<Person> searchByMajors(Person[] listPerson, String majors){
        // bổ sung mã lệnh ở đây để liệt kê các đối tượng Student trong listPerson có trường majors
        // trùng với tham đối majors! Có thể sửa giá trị trả về của lệnh return
        // nhưng không thay đổi kiểu trả về!
        ArrayList<Person> results = new ArrayList<>();
        for(Person it : listPerson) {
            if (it.getCode().charAt(0) == '1') {
                Student tmp = (Student) it;
                if (tmp.getMajors().equals(majors)) {
                    results.add(tmp);
                }
            }
        }
        return results;
    }


    public static void main(String Ag[]){
        Scanner scan = new Scanner(System.in);
        scan.nextLine();
        currentYear = Integer.parseInt(scan.nextLine());
        Person[] listPerson = readData(scan);
//        displayList(listPerson);
//        sortByLastName(listPerson);
        displayList(listPerson);
        // Chỉ cần viết main để kiểm thử theo ý người lập trình
        // Phần chạy thử & chấm trên hệ thống đã có lớp khác.
    }

}