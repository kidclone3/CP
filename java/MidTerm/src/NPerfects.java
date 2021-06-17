// Bài thực hành in ra các số hoàn hảo nhỏ hơn n với n được nhập từ bàn phím
//Kết quả in trên một dòng các số được cách nhau bởi một dấu cach

class NPerfects
{
    // Hàm kiểm tra số n có phải là số hoàn hảo hay không
    // nếu n là số hoàn hảo thì trả về true, ngược lại trả về false
    static boolean isPerfect(int n)
    {
        //begin edit
        int sum = 1;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                if (i == n/i) sum+=i;
                else sum += i + n/i;
            }
        }
        return sum == n;
        //end edit

    }
    // hàm in ra các số hoàn hảo nhỏ hơn n trên cùng dòng, ví dụ n = 100 kết quả in ra là:
    // 6 28

    static void printNPerfect(int n)
    {
        for (int i = 0; i < n + 1; i++) {
            if (isPerfect(i)) {
                System.out.printf("%d ",i);
            }
        }
    }
    public static void main (String args[])
    {

    }
}