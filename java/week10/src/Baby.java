public class Baby implements Comparable<Baby> {

    // khai báo các thuộc tính của một baby
    // tạo tất cả các hàm dựng (có đối và không đối)
    // xây dựng các hàm getter, setter phù hợp với các thuộc tính
    private String day = "01/01/2020";
    private String name = "UnRegistered";
    private boolean gender;
    private double weight, length;
    public Baby() {
    }

    public Baby(String bbName, String bbDay, boolean bbGender, double bbWeight, double bbLength) {
        this.name = bbName;
        this.day = bbDay;
        this.gender = bbGender;
        this.weight = bbWeight;
        this.length = bbLength;
    }
    /*
        Lưu ý, đối với hàm public String getGender() sẽ trả về Boy nếu gender = false, ngược lại trả về "Girl"
    */
    public String getGender() {
        return (this.gender ? "Girl" : "Boy");
    }
    public String getName() {
        return this.name;
    }
    // in ra thong tin cua baby theo thu tu: ten, ngay thang nam sinh, gioi tinh, can nang, chieu cao
    public String toString() {
        return getName() + " " + this.day + " " + getGender() + "  " + this.length + " " + this.weight;
    }

    @Override
    public int compareTo(Baby bb) {
        double compareWeight = ((Baby) bb).weight;
        return Double.compare(compareWeight, this.weight);
    }
}