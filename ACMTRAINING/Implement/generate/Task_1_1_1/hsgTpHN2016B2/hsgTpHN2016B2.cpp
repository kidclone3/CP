/*
Trong cuộc thi hsg Tin học, mỗi thí sinh phải trả lời n câu hỏi. Ban tổ chức đưa ra n số điểm thưởng a[1], ..., a[n]. Theo thể lệ, người làm được k câu hỏi (1 <= k <= n) sẽ nhận đc điểm thưởng là số lớn nhất trong {a[1], ..., a[k]}. Tính số điểm thưởng mà từng người nhận được.
INPUT:
	Dòng 1: Số nguyên dương n <= 300000;
	Dòng 2: n số nguyên dương <= 10^3
OUTPUT:
	1 dòng n số là điểm thưởng tương ứng thí sinh làm được 1, 2, ..., n câu hỏi.
*/
#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    int a[n], ans[n];
    int curr = INT_MIN;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        curr = max(curr, a[i]);
        ans[i] = curr;
    }
    for(int i = 0; i < n; ++ i) {
        cout << ans[i] << " ";
    }
}
