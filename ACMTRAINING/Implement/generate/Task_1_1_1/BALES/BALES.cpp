/*
Chú voi Dum đang quản lí một nông trang lớn. Chú ta nuôi một đàn bò rất đẹp để lấy thịt
và sữa. Tuy nhiên những chú bò này lại rất tinh nghịch. Dum đã cẩn thận sắp xếp 𝑁 (1 ≤
𝑁 ≤ 10000) đống kiện hàng (trong một đống có nhiều kiện), các đống này có cùng chiều
cao. Tuy nhiên, khi ông ta không trông chừng, những con bò di chuyển một số kiện hàng
hóa giữa các đống kiện hàng, vì vậy chiều cao của chúng không bằng nhau nữa. Bạn được
cho chiều cao mới của các đống kiện hàng (tương ứng với số lượng kiện hàng trong 1 đống),
hãy giúp Dum tính số lượng các kiện hàng hóa nhỏ nhất mà chú ta phải di chuyển để khôi
phục lại các đống kiện hàng hóa như ban đầu. 
*/
#include<bits/stdc++.h>
using namespace std;
int main() {

//  Bai nay chi la tinh trung binh cong.

    int n; cin >> n;
    vector<int> a(n);
    int sum = 0;
    for (int i = 0; i < n; i++) cin >> a[i], sum += a[i];
    int ans = 0;
    for (int i = 0; i < n; i++) if (a[i] > sum/n) ans += a[i] - sum/n;
    cout << ans;
}
