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
*/
// #include<bits/stdc++.h>
#include<iostream>
#include<vector>
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
    // 10^4 => 10^8 la` chay dc trong 1s.
    for(int i = 0; i < n; ++i) {
        long long l, r, x;
        cin >> l >> r >> x;
        for(int j = l; j <= r; ++j) {
            if ((j - l) & 1) p[j] -= x;
            else p[j] += x;
        }
    }

    for(int i = 0; i < m; ++i) {
        cout << p[i] << " ";
    }
}
