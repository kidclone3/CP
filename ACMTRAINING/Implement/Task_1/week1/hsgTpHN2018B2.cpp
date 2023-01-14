/*
Đề:
Để động viên học sinh tham dự kì thi hsg năm nay, trường ITS
có chuẩn bị n phần quà cho n thí sinh. Trên hộp quà thứ i có
số nguyên a[i], các số a[i] đôi một khác nhau với mọi i. Sau 
khi tặng quà, nhà trường sẽ có thêm những cặp quà đặc biệt cho
các cặp đôi (i, j) mà a[i] + a[j] = 0.
Yêu cầu:
	Cho biết nhà trường cần chuẩn bị bao nhiêu cặp quà
INPUT:
	Dòng 1: số nguyên dương n
	Dòng 2: n số nguyên a[1], ..., a[n]
OUTPUT:
	Một số duy nhất là số lượng các cặp quà cần chuẩn bị
Giới hạn: n <= 10^6, |a[i]| <= 10^9

Giải:
Đầu tiên ta có nhận xét
a[i] + a[j] = 0 => a[i] = -a[j]. Vậy nên, với mỗi a[i], ta sẽ đếm xem có bao nhiêu giá trị j (j < i) thoả mãn a[i] = -a[j].
Từ nhận xét này, ta có 2 cách giải:
1. Sử dụng map để đếm xem có bao nhiêu giá trị -a[j]. 
Độ phức tạp nếu dùng của map là O(nlogn), với n là số phần tử.
Ngoài ra nếu dùng unordered_map (các ngôn ngữ khác là hash map) thì độ phức tạp là O(n). Cách dưới cũng có đpt tương tự.
Nếu giới hạn của a[i] là 10^6, ta có thể lưu trên mảng thông thường. Tuy vậy mảng không lưu được các chỉ số âm, vậy nên dùng thêm 1 biến làm mốc đủ lớn để dịch lên là được.

Cách dùng tìm kiếm nhị phân có đpt O(nlogn), sẽ được giải thích ở những buổi sau.
*/
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    int a[n];
    for (int i = 0; i < n; ++ i) {
        cin >> a[i];
    }
    
    // Cach 1: dung map:
    int ans = 0;
    map<int, int> mp;
    for (int i = 0; i < n; ++ i) {
        ans += mp[-a[i]];
        mp[a[i]]++;
    }
    cout << ans+n;

    // Cach 2: Dung tknp;
    //     int ans = 0;
    //     cout << "Cach 2: Tknp";
    //     sort(a, a+n);
    //     for(int i = 0; i < n; ++ i) {
    //         auto tmp = equal_range(a,a+n, -a[i]);
    //         ans += tmp.second - tmp.first;
    //     }
    //     cout << ans/2 + n;
}
