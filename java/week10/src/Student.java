public class Student{

    private String msv, hovaten; // Thuộc tính mã sinh viên msv, họ tên hovaten
    private double diem;        // Thuộc tính điểm diem

    // Hàm dựng với 3 đối số cho Họ tên, mã sinh viên và điểm
    // chu ý với những biến trùng tên, để phân biệt giũa biến của lớp (class) và biến cục bộ của phương thức sử dụng this.
    public Student(String hoten, String masinhvien, double diem)
    {
        this.hovaten = hoten;
        this.msv = masinhvien;
        this.diem = diem;
    }
    // Phương thức in ra thông tin của sinh viên trên 1 dòng gồm : Mã sinh viên, họ và tên, điểm, Điểm lấy đến 1 chữ số thập phân, ví dụ 8.0
    double getDiem() {
        return this.diem;
    }
    public void printInfor()
    {
        System.out.println(msv + " " + hovaten + " " + diem);
    }
}