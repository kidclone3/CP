#include <bits/stdc++.h>
using namespace std;

int nonDivisibleSubset(int k, vector<int> s) {
    map<int, int> mp;
    for (auto it : s) {
        mp[it % k]++;
    }
    int ans = 0;
    if (mp[0] > 0) ans++;
    for (int i = 1; i <= k / 2; i++)
    {
        if (i != k - i) {
            ans += max(mp[i], mp[k-i]);
        }
        else {
            if (mp[i] > 0) ans++;
        }
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
    cout << nonDivisibleSubset(k, a);
    
}