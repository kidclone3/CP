public class MovementTime {
    public static void main(String[] args) {
        double S = Double.parseDouble(args[0]);
        double v0 = Double.parseDouble(args[1]);
        double a = Double.parseDouble(args[2]);
        if( S > 0 && v0 > 0 && a > 0) {
            // nghiem cua phuong trinh bac 2.
//          S = 1/2at^2 + vo.t
            double delta = (v0 * v0) - 4*(1/2 * a * S);//b^2 - 4ac
            if (delta <0) {
                System.out.println(-1);
                return;
            }
            else {
                // -b +- sqrt(delta)/ 2.a
                double ans1 = (-v0 + Math.sqrt(delta)) / (2*1/2*a);
                double ans2 = (-v0 - Math.sqrt(delta)) / (2*1/2*a);
                double res = Math.max(ans1, ans2);
                System.out.println(res);
            }
        }
        else {
            System.out.println(-1);
            return;
        }
    }
}
