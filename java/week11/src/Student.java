/** Class Student: 
 * Dẫn xuất từ (con của) lớp Person. Cần hoàn thiện các phương thức chưa có
 * nhưng phải giữ nguyên mẫu phương thức (khai báo, đối số, kiểu trả về)
 * Có thể thay đổi giá trị sau lệnh return cuối các phương thức nhưng cần
 * giữ nguyên kiểu trả về. Có thể bổ sung phương thức nếu cần, nhưng phải 
 * giữ lại đầy đủ các phương thức đã được khai báo sẵn
 * */

public class Student extends Person{
    private String  majors = "UnRegistered";
    private double scoreAvg;

    public Student(){
        // bổ sung mã lệnh ở đây 
        scoreAvg = 0.0;
    }

    public Student(String SVcode, String mail, String majors, double score,
                   String name, Date birthday, boolean gender, String address){
        // bổ sung mã lệnh ở đây
        super(SVcode, name, birthday, gender, mail, address);
        this.majors = majors;
        this.scoreAvg = score;
    }


    public String getMajors(){
        // bổ sung mã lệnh ở đây! Có thể sửa giá trị trả về của lệnh return
        // nhưng không thay đổi kiểu trả về!
        return this.majors;
    }

    public double getScore(){
        // bổ sung mã lệnh ở đây! Có thể sửa giá trị trả về của lệnh return
        // nhưng không thay đổi kiểu trả về!
        return this.scoreAvg;
    }

    public double getPayment(double baseAmount){

        // bổ sung mã lệnh ở đây! Có thể sửa giá trị trả về của lệnh return
        // nhưng không thay đổi kiểu trả về!
        if (this.scoreAvg < 4.0) {
            return 1.5 * baseAmount;
        }
        else if (this.scoreAvg < 8.0) {
            return baseAmount;
        }
        else if (this.scoreAvg < 9.0){
            return 0.75 * baseAmount;
        }
        else {
            return 0.5 * baseAmount;
        }
    }

    @Override
    public String toString(){
        String str =  "Student Code: " + super.toString() + "; AVG score:" + String.valueOf(scoreAvg) + " Majors: " + majors;
        // bổ sung mã lệnh ở đây! Có thể sửa giá trị trả về của lệnh return
        // nhưng không thay đổi kiểu trả về!
        return str;
    }

}