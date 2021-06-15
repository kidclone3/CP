import java.lang.module.ModuleReader;
import java.util.ArrayList;
import java.util.Scanner;

public class MotorbikeTest {
        static Scanner sc = new Scanner(System.in);
            public static void inputMotorbike(ArrayList<Motorbike> motorbikes, int n) {
                    for (int i = 0; i < n; i++) {
                            String id, name, manu, date;
                            int quantity;
                            double price, weight;
                            id = sc.nextLine();
                            name = sc.nextLine();
                            manu = sc.nextLine();
                            quantity = Integer.parseInt(sc.nextLine());
                            price = Double.parseDouble(sc.nextLine());
                            weight = Double.parseDouble(sc.nextLine());
                            date = sc.nextLine();

                            Motorbike tmp = new Motorbike(id, name, manu, quantity, price, weight, date);
                            motorbikes.add(tmp);
                    }
            }

            public static void ouputMotorbike(ArrayList<Motorbike> motorbikes) {
                    for (Motorbike it : motorbikes) {
                        it.printMotorbike();
                    }
            }

            public static ArrayList<Motorbike> search(String manu, ArrayList<Motorbike> motorbikes) {
                    ArrayList<Motorbike> ans = new ArrayList<>();
                    for (Motorbike it : motorbikes) {
                        if (it.getManu().equals(manu)) {
                            ans.add(it);
                        }
                    }
                    return ans;
            }

            public static ArrayList<Motorbike> maxWeight(ArrayList<Motorbike> motorbikes) {
                    double mx = -1e9;
                    ArrayList<Motorbike> ans = new ArrayList<>();
                    for (Motorbike it : motorbikes) {
                        if (it.getWeight() > mx) {
                            mx = it.getWeight();
                        }
                    }
                    for (Motorbike it : motorbikes) {
                        if (it.getWeight() == mx) {
                            ans.add(it);
                        }
                    }
                    return ans;
            }

            public static ArrayList<Motorbike> minQuanlity(ArrayList<Motorbike> motorbikes) {
                int mn = (int) 1e9;
                ArrayList<Motorbike> ans = new ArrayList<>();
                for (Motorbike it : motorbikes) {
                    if (it.getQuantity() < mn) {
                        mn = it.getQuantity();
                    }
                }
                for (Motorbike it : motorbikes) {
                    if (it.getQuantity() == mn) {
                        ans.add(it);
                    }
                }
                return ans;
            }

            public static void main(String[] args) {
                // TODO Auto-generated method stub

                    int n = sc.nextInt();
                    sc.nextLine();
                    ArrayList<Motorbike> motorbikes = new ArrayList<>();
                    inputMotorbike(motorbikes, n);
                    int c = sc.nextInt();
                    ArrayList<Motorbike> ans = new ArrayList<>();
                    switch (c) {
                        case 1: {
                            ans = search("Honda", motorbikes);
                            break;
                        }
                        case 2: {
                            ans = maxWeight(motorbikes);
                            break;
                        }
                        case 3: {
                            ans = minQuanlity(motorbikes);
                            break;
                        }
                    }
                    ouputMotorbike(ans);
            }
}