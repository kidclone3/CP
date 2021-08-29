#include <bits/stdc++.h>
using namespace std;

const int zero = 1e5 + 5;
const int N = 2e5+10;

bool ok(int k, vector<int> a) {
    int n = a.size();
    vector<int> dp(N, 0);
    int left = INT_MAX;
    int right = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == 1) {
            dp[zero + i-k+1] ++;
            dp[zero + i + k] --;
            left = min(left, zero + i-k+1);
            right = max(right, zero + i +k);
        }
    }
    for(int i = left; i <= right; ++i) {
        dp[i] = dp[i-1] + dp[i];
    }
    for(int i = 0; i < n; ++i) {
        if (!dp[zero + i]) {
            return false;
        }
    }
    return true;
}

int pylons(int k, vector<int> arr) {
    int n = arr.size();
    if (!ok(k, arr)) {
        return -1;
    }
    vector<int> electric;
    for(int i = 0; i < n; ++i) {
        if (arr[i] == 1) electric.push_back(i);
    }
    int ans = 0;
    int i = -1;
    bool first = true;
    while(i < n) {
        int dis = 2 * k - 1;
        if (first) {
            dis = k;
            first = false;
        }
        auto it = lower_bound(electric.begin(), electric.end(), i + dis);
        if (it == electric.end() || *it != i+dis) it--;
        if (*it == i) break;
        i = *it;
        ans++;
        // cout << i << " ";
    }
    return ans;
}

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << pylons(k, a);
}