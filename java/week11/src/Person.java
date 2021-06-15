/**
 * Lớp Person - cơ sở của các lớp Student và Staff.
 * Các phương thức dựng không tham số và đủ tham số.
 * Trường name cần được chuẩn hóa bằng phương thức String normalizeName(String) trước khi gán
 * Các phương thức đã định nghĩa đầy đủ thì không cần thay đổi. Các phương thức khác cần viết đủ
 * nhưng phải giữ nguyên cấu trúc khai báo/định nghĩa và kiểu trả về, chỉ thay giá trị sau lệnh return
 * Có thể bổ sung phương thức nếu cần, nhưng phải giữ lại đầy đủ các phương thức đã được khai báo sẵn
 * */
public class Person{
    private String personCode = "00000000";
    private String name = "UnRegistered";
    private Date birthday = new Date();
    private boolean gender;
    private String email = "Un@Registered";
    private String address = "UnRegistered";

    public Person(){
    }

    public Person(String code, String name, Date birthday, boolean gender, String mail, String address){

        this.personCode = code;
        this.name = normalizeName(name);
        this.birthday = birthday;
        this.gender = gender;
        this.email = mail;
        this.address = address;
        // bổ sung mã lệnh ở đây
    }

    public static String normalizeName(String name){
        String str = name;
        str = str.trim();
        str = str.replaceAll("\\s+"," ");
        char[] ch = str.toCharArray();

        ch[0] = Character.toUpperCase(ch[0]);

        for(int i = 1 ; i < ch.length; i++)
            if(ch[i-1] == ' ')
                ch[i] = Character.toUpperCase(ch[i]);
            else
                ch[i] = Character.toLowerCase(ch[i]);

        return String.valueOf(ch);
    }

    public String getLastName(){

        int l = name.length() - 1;
        while(l > 0 && name.charAt(l) != ' ')
            l--;

        return name.substring(l + 1 , name.length());
    }

    public String toString(){
        // bổ sung mã lệnh ở đây! Có thể sửa giá trị trả về của lệnh return
        // nhưng không thay đổi kiểu trả về!
        String result = personCode + ": " + getName() + "; B.day: " + getBirthday() + " (" + getGender() + ") Mail: " + email +"; Addr:" + getAddress();
        return result;
    }

    public int getAge(int currentYear) throws ArithmeticException{
        if (birthday.getYear() > currentYear)
            throw new ArithmeticException("Birthday: Invalidate data! Year of birth has to be less than current year!");
        return currentYear - birthday.getYear();
    }

    public String getCode(){
        // bổ sung mã lệnh ở đây! Có thể sửa giá trị trả về của lệnh return
        // nhưng không thay đổi kiểu trả về!
        return this.personCode;
    }

    public String getName(){
        // bổ sung mã lệnh ở đây! Có thể sửa giá trị trả về của lệnh return
        // nhưng không thay đổi kiểu trả về!
        return this.name;
    }

    public String getBirthday(){
        return this.birthday.toString();
    }

    public String getGender(){
        if(this.gender)
            return "Male";
        else
            return "FeMale";
    }

    public String getEmail(){
        // bổ sung mã lệnh ở đây! Có thể sửa giá trị trả về của lệnh return
        // nhưng không thay đổi kiểu trả về!
        return this.email;
    }

    public String getAddress(){
        // bổ sung mã lệnh ở đây! Có thể sửa giá trị trả về của lệnh return
        // nhưng không thay đổi kiểu trả về!
        return this.address;
    }

}