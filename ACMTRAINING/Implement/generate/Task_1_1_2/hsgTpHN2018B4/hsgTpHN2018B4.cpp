/*
Đề:
Cho bảng mxn tấm bìa, trên mỗi tấm bìa ghi một số. Lúc đầu, tất 
cả các tấm bìa đều nằm ngửa, để lộ ra số ghi trên đó, tấm bìa ở
hàng i cột j sẽ có số a[i][j]. Nếu chọn lật tấm bìa có số a[i][j]
thì tất cả các tấm bìa khác mà có cùng số trên đó cũng sẽ được úp 
xuống. Cho trước số k, yêu cầu chọn không quá k lần và thực hiện
thao tác lật để được số bìa úp là nhiều nhất có thể.
INPUT:
	Dòng 1: 3 số nguyên dương m, n, k
	m dòng tiếp theo: mỗi dòng gồm n số nguyên a[i][j] tương ứng với hàng m cột n
OUTPUT:
	1 số duy nhất là kết quả
Giới hạn: 
	m, n, <= 1000; k <= m*n
*/
#include <bits/stdc++.h>
using namespace std;
int main() {
    int m, n, k;
    cin >> m >> n >> k;
    // Bai toan dem, dung map.
    map<int, int> mp;
    for(int i = 0; i < m; ++i) {
        for(int j = 0; j < n; ++j) {
            int x; cin >> x;
            mp[x]++;
        }
    }
    vector<int> tmp;
    for(auto &it : mp) {
        tmp.push_back(it.second);
    }
    sort(tmp.begin(), tmp.end(), greater<int>());
    long long ans = 0LL;
    // for(auto &it : tmp) cout << it << " ";
    assert((int) tmp.size() >= k);
    for(int i = 0; i < k; ++i) {
        ans += tmp[i]*1LL;
    }
    cout << ans;
}
