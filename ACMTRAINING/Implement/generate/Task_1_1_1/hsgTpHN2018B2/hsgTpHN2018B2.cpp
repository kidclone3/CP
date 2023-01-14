/*
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
    // {
    //     cout << "Cach 1: Dung map";
    //     int ans = 0;
    //     map<int, int> mp;
    //     for (int i = 0; i < n; ++ i) {
    //         ans += mp[-a[i]];
    //         mp[a[i]]++;
    //     }
    //     cout << ans+n;
    // }

    // Cach 2: Dung tknp;
    {
        int ans = 0;
        // cout << "Cach 2: Tknp";
        sort(a, a+n);
        for(int i = 0; i < n; ++ i) {
            auto tmp = equal_range(a,a+n, -a[i]);
            ans += tmp.second - tmp.first;
        }
        cout << ans/2 + n;
    }
}
