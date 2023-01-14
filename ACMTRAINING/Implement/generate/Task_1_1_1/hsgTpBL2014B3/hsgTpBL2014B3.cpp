/*
Cho ma trận vuông A(nxn) với n <= 100, các phần tử a[i][j] có giá trị nguyên dương (a[i][j] <= 100).
Sắp xếp ma trận theo thứ tự giảm dần từ phải sang trái, từ trên xuống dưới
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
    sort(ans.begin(), ans.end());
    reverse(ans.begin(), ans.end());
    int curr = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = n-1; j > -1; --j) {
            cout << ans[curr+j] << " \n"[j==0];
        }
        curr += n;
    }
}
