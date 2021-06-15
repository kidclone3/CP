/** Lớp Date với các trường: day, month, year - cho ngày, tháng, năm
 *   Hàm dựng với đầy đủ tham số, các tham số sẽ được kiểm tra tính
 *   phù hợp thông qua phương thức boolean isValidate(int d, int m, int y)
 *   Các phương thức get và set cần thiết để đặt và trả lại các trường
 *   Phương thức String toString() trả lại xâu ngày tháng, ví dụ "23/07/2020"
 * */
public class Date{
    private int year;
    private int month;
    private int day;

    public Date(){
        year = 2000;
        month = 1;
        day = 1;
    }

    public Date(int yy, int mm, int dd){
        if(isValidate(dd, mm, yy)){
            year = yy;
            month = mm;
            day = dd;
        }
        else{
            year = 2000;
            month = 1;
            day = 1;
        }
    }

    public int getDay(){
        return day;
    }

    public int getYear(){
        return year;
    }

    public int getMonth(){
        return month;
    }

    public void setDay(int d){
        day = d;
    }

    public void setYear(int y){
        year = y;
    }

    public void setMonth(int m){
        month = m;
    }

    public String toString(){
        String str = String.valueOf(day) + "/";
        if(day < 10)
            str = "0"+  str;
        if(month < 10)
            str = str + "0";
        str = str + String.valueOf(month)+"/";

        return str + String.valueOf(year);
    }

    public static boolean isValidate(int d, int m, int y){
        if(!(d > 0 && d < 32 && m > 0 && m < 13 && y > 0))
            return false;
        int day_num = 0;
        switch (m){
            case 4:
            case 6:
            case 9:
            case 11: day_num = 30; break;
            case 2: if(y % 400 == 0 || (y % 100 != 0 && y % 4 ==0))
                day_num = 29;
            else day_num = 28; break;
            default: day_num = 31;
        }
        if (d > day_num) return false;
        return true;
    }
}
