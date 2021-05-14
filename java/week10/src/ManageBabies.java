import java.util.*;

public class ManageBabies {



	/*  Nhap vao thong tin cua n baby tu ban phim. Cac thong tin theo thu tu ten, ngay thang nam sinh, gioi tinh
	gioi tinh, can nang, chieu cao
	*/

    // nhap vao so nguyen duong n va thong tin cua n baby
    public static Baby[] createData (Scanner sc)
    {
        int n = sc.nextInt();
        Baby[] data = new Baby[n];
        for (int i = 0; i < n; i++) {
            sc.nextLine();
            String bbName = sc.nextLine();
            String bbDay = sc.nextLine();
            boolean bbgender = sc.nextBoolean();
            int bbWeight = sc.nextInt();
            int bbLength = sc.nextInt();
            Baby tmp = new Baby(bbName, bbDay, bbgender, bbWeight, bbLength);
            data[i] = tmp;
        }
        return data;
    }

    // In ra thong tin cua n baby sau khi chuan hoa ho ten
    public static void printInforBabies (Baby babies[])
    {
        for (Baby i : babies) {
            System.out.println(i.toString());
        }
    }
    // Sap xep cac baby theo trong luong giam dan
    void sortWeight (Baby babies[])
    {
        Arrays.sort(babies);
    }
    // Loc ra tat ca nhung baby co gioi tinh la gender
    void filterGender(Baby babies[], String gender)
    {
        for (Baby it : babies) {
            if (it.getGender().equals(gender)){
                System.out.println(it.toString());
            }
        }
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Baby[] data = createData(sc);
        printInforBabies(data);
    }

}