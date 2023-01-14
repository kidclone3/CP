/*
Các cô bò của Dum chuẩn bị tham gia cuộc thi Hoa hậu bò sữa. Các thí sinh phải chuẩn
bị phần thi “Cô bò ăn ảnh” vì thế Dum quyết định sắm một cái máy ảnh mới. Chiếc
máy của chú ta có thẻ nhớ dung lượng là d megabytes (MB). Tùy mức độ điều chỉnh
máy ảnh mà có thể chụp những bức ảnh có chất lượng cao hay thấp, một bức ảnh có
chất lượng thấp sẽ chiếm dung lượng là a MB của không gian trống trong thẻ nhớ,
một bức ảnh có chất lượng cao sẽ chiếm dung lượng là b MB của không gian trống
trong thẻ nhớ.
Có 𝑵 cô bò sẽ được chụp ảnh (đánh số thứ tự từ 1 đến 𝑁), cô bò thứ i yêu cầu chụp
xi bức ảnh chất lượng thấp và yi bức ảnh chất lượng cao. 
Hãy giúp nhiếp ảnh gia Dum của chúng ta đưa ra phương án hợp lý để có thể phục
vụ được nhiều cô bò nhất.
*/
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    int n; cin >> n; // n la so luong muon chup
    int d; cin >> d; // k la dung luong cua bo nho.
    ll aa, bb; cin >> aa >> bb;
    vector<ll> a;
    for(int i = 0; i < n; ++ i) {
        ll x, y; cin >> x >> y;
        a.push_back(x*aa+y*bb);
    }
    // Sap xep theo tong dung luong cac con bo` can.
    sort(a.begin(), a.end());
    ll curr = 0LL;
    int i;
    for(i = 0; i < n; ++i) {
        curr += a[i];
        if (curr > d) break;
    } 
    cout << i << "\n";
    // for(i = 0; i < n; ++i) cout << a[i] << " ";
}
