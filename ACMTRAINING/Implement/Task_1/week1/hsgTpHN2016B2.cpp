/*
Đề:
Trong cuộc thi hsg Tin học, mỗi thí sinh phải trả lời n câu hỏi. Ban tổ chức đưa ra n số điểm thưởng a[1], ..., a[n]. Theo thể lệ, người làm được k câu hỏi (1 <= k <= n) sẽ nhận đc điểm thưởng là số lớn nhất trong {a[1], ..., a[k]}. Tính số điểm thưởng mà từng người nhận được.
INPUT:
	Dòng 1: Số nguyên dương n <= 300000;
	Dòng 2: n số nguyên dương <= 10^3
OUTPUT:
	1 dòng n số là điểm thưởng tương ứng thí sinh làm được 1, 2, ..., n câu hỏi.

Giải: Hầu như các bạn lúc học đều đã thực hiện được. Chúng ta tạo 1 biến để lưu giá trị lớn nhất khi duyệt đến phần tử thứ i (từ 1 đến i). Đấy cũng là kết quả của câu hỏi.

Input:
    5
    3 2 1 4 5
Output:
    3 3 3 4 5
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
