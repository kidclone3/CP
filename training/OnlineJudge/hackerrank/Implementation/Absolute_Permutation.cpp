#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+5;
bool check[N];
vector<int> absolutePermutation(int n, int k) {
    for(int i = 0; i <= n; ++i) check[i] = 0;
    check[0] = 1;
    vector<int> ans(n);
    for(int i = n; i >= 1; --i) {
            if (i + k <= n && !check[i+k]) {
                ans[i-1] = i + k;
                check[i+k] = 1;
            }
            else if (i - k > 0 && !check[i-k]) {
                ans[i-1] = i - k;
                check[i-k] = 1;
            }
            else return {-1};
    }
    return ans;
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, k;
        cin >> n >> k;
        vector<int> ans = absolutePermutation(n, k);
        for (auto &it : ans) {
            cout << it << " ";
        }
        cout << '\n';
    }
}