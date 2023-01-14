/*
    Đề: Cho ma trận vuông A(nxn) với n <= 100, các phần tử a[i][j] có giá trị nguyên dương (a[i][j] <= 100).
        Sắp xếp ma trận theo thứ tự giảm dần từ phải sang trái, từ trên xuống dưới

    Giải: Lấy hết tất cả các phần tử rồi cho vào 1 mảng, sau đấy thực hiện sắp xếp và in ra.
        Lưu ý, lúc in ra phải khéo léo 1 chút.
    Input:
        3
        1 2 3
        4 5 6
        7 8 9
    Output:
        7 8 9
        4 5 6
        1 2 3
*/

#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; cin >> n;
    // int a[n][n];
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int x;
            cin >> x; 
            ans.push_back(x);
        }
    }
    sort(ans.begin(), ans.end(), greater<int>());
    int curr = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = n-1; j > -1; --j) {
            cout << ans[curr+j] << " \n"[j==0];
        }
        curr += n;
    }
}
