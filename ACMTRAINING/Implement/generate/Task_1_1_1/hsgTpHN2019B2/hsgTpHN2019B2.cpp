/* Đề:
Để nghiên cứu về tác động của biến đổi khí hậu, An tiến hành một thí nghiệm với kịch bản như sau:
An chọn một vị trí trên bản đồ và đánh số từ 1 cho đến hết. Ban đầu, độ cao so với mực nước biển
của các vị trí = 0. AN sẽ thực hiện n tác động biến đổi khí hậu được đánh số từ 1 đến n. Tác động thứ
i sẽ làm thay đổi độ cao của vị trí có số hiệu từ l[i] đến r[i] theo quy tắc: l[i] sẽ tăng thêm x[i], 
l[i] + 1 sẽ giảm đi x[i], l[i] + 2 lại tăng thêm x[i], ... cứ thế đến r[i].
Yêu cầu: xác định độ cao của m vị trí p[1], p[2], ..., p[m] sau khi thực hiện n tác động:
INPUT:
	Dòng 1: 2 số nguyên dương m, n
	m dòng tiếp theo: mỗi dòng chứa 1 số nguyên dương tương ứng với một vị trí p[i]
	n dòng tiếp theo: mỗi dòng chứa 3 số nguyên dương l[i], r[i], x[i] tương ứng với tác động thứ i
OUTPUT:
	m dòng, mỗi dòng là độ cao của p[i] sau tất cả các tác động
Giới hạn: 
	m, n <= 10^4

Testcase:
Input: 
    
Giải: Cách trâu có thể chạy được 1 cách xuýt xoa, do yêu cầu đầu bài có vẻ khả thi. Đpt O(n^2)
Cách giải đúng sẽ là dùng đếm phân phối bằng 2 mảng (vì 2 cái ngược dấu nhau).
Mảng d1 sẽ cộng các giá trị x khi l nhập vào là số chẵn, ngược lại d2 sẽ cộng các giá trị x khi l nhập vào là lẻ.
Sau đấy, ta cần tìm ra vị trí l nhỏ nhất (min_l) và lấy nó làm mốc xuất phát.
Giá trị của p[i] sẽ bằng p[i] + d1[i]-d2[i] hoặc p[i] + d2[i] - d1[i] tuỳ xem vị 
trí i đến min_l là chẵn hay lẻ, và min_l là chẵn hay lẻ. Đọc code để rõ hơn.
PS: Code này hơi củ chuối, nhưng mình lười viết ngắn lại :))
*/
#include<bits/stdc++.h>
// #include<iostream>
// #include<vector>
// #include<climits>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int m, n;
    cin >> m >> n;
    vector<long long> p(m);
    // l[i] tang x[i], l[i+1] giam x[i];
    for(int i = 0; i < m; ++i) {
        cin >> p[i];
    }
    int min_l = INT_MAX;
    vector<long long> d1(m+5, 0), d2(m+5, 0);
    for(int i = 0; i < n; ++i) {
        int l, r;
        long long x;
        cin >> l >> r >> x;
        min_l = min(l, min_l);
        if (l % 2 == 0) {
            d1[l] += x; 
            d1[r+1] -= x;
        }
        else {
            d2[l] += x; 
            d2[r+1] -= x;
        }
    }
    for (int i = 0; i < m; ++i) {
        if (i > 0) {
            d1[i] += d1[i-1];
            d2[i] += d2[i-1];
        }
        if (min_l % 2 == 0) {
            if (i % 2 == 0) 
                p[i] += d1[i] - d2[i];
            else 
                p[i] += d2[i] - d1[i];
        } else {
            if (i % 2 == 1)
                p[i] += d2[i] - d1[i];
            else
                p[i] += d1[i] - d2[i];
        }
        cout << p[i] << " ";
    }
}