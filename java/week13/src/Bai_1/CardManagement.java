package Bai_1;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class CardManagement {
    public CardManagement()
    {
        super();
    }
    /*
        Thứ tự nhập như sau:
        - Số lượng xe
        - Trong vòng lặp để nhập thông tin mỗi thẻ: nhập số nguyên c = 0 (thẻ học sinh) hoặc 1 (thẻ nhân viên)
        - Nhập thông tin mỗi thẻ: id, years, day, price, fee (với thẻ sinh viên), và card (với thẻ học sinh)
    */
    public ArrayList<Card> readData (String fileName) throws FileNotFoundException {
        File myfile = new File(fileName);
        Scanner sc = new Scanner(myfile);
        int n = Integer.parseInt(sc.nextLine());
        ArrayList<Card> ans = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            int c = Integer.parseInt(sc.nextLine());
            String id = sc.nextLine();
            int year = Integer.parseInt(sc.nextLine());
            double day = Double.parseDouble(sc.nextLine());
            double price = Double.parseDouble(sc.nextLine());
            double fee = Double.parseDouble(sc.nextLine());
            if (c==0) {
                StudentCard tmp = new StudentCard(id, year, day, price, fee);
                ans.add(tmp);
            }
            else {
                StaffCard tmp = new StaffCard(id, year, day, price, fee);
                ans.add(tmp);
            }
        }
        return ans;
    }

    public void printArrayList(ArrayList<Card> cards) {
        for (int i =0;i<cards.size();i++)
            System.out.println(cards.get(i).toString());
    }
    // Hoan thien phuong thuc findCards de tim nhung  xe co nam san xuat la year

    public ArrayList<Card> findCards (ArrayList<Card> cards, int year){
        //Begin editable part
        ArrayList<Card> ans = new ArrayList<>();
        for (Card it : cards) {
            if (it.getYear() == year) {
                ans.add(it);
            }
        }
        return ans;
        //End editable part
    }

    // Hoan thien phuong thuc getMaxAmount de tim cac xe thuoc the loai typeOfCard
    public ArrayList<Card> getMaxAmount (ArrayList<Card> cards, String typeOfCard){
        //Begin editable part
        ArrayList<Card> ans = new ArrayList<>();
        double mx = 0;
        for (Card it : cards) {
            if (it.getClass().getName().equals(typeOfCard)) {
                if (it.getAmount() > mx) {
                    mx = it.getAmount();
                }
            }
        }
        for (Card it : cards) {
            if (it.getClass().getName().equals(typeOfCard)) {
                if (it.getAmount() == mx) {
                    ans.add(it);
                }
            }
        }
        return ans;
        //End editable part
    }


    // Hoan thien phuong thuc sortByAmount de sap xep cac xe theo thu tu giam dan
    public void sortByAmount (ArrayList<Card> cards) {
        //Begin editable part
        int n = cards.size();
        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                if (cards.get(i).getAmount() < cards.get(j).getAmount()) {
                    Card tmp = cards.get(i);
                    cards.set(i, cards.get(j));
                    cards.set(j, tmp);
                }
            }
        }
        //End editable part
    }
    public static void main(String[] args) throws Exception{
        // TODO Auto-generated method stub
        CardManagement cardMng = new CardManagement();
        ArrayList<Card> cards = cardMng.readData("src/Bai_1/datas.txt");
        cardMng.printArrayList(cards);
        ArrayList<Card> tmp = cardMng.getMaxAmount(cards, "StaffCard");
//        for (Card it : tmp) {
//            System.out.println(it.toString());
//        }
    }

}