#include <bits/stdc++.h>
using namespace std;
template <class T>
void print(T &x)
{
    for (auto &it : x)
    {
        cout << "{" << it.first << ", " << it.second << "}, ";
    }
    cout << "\n\n";
};

long long maxSumOfBeautifulSubarray(std::vector<int> arr)
{
    int n = arr.size();
    vector<long long> dp(1+2*n, 0), dp_mod(1 + 2*n);
    for(int i = 0; i < 2*n; ++i) {
        dp[i+1] = dp[i] + arr[i%n];
        dp_mod[i+1] = (dp[i+1] % 9 + 9) % 9;
    }
    long long mx = LLONG_MIN;
    set<pair<long long, int>> mp[10];
    mp[0].insert({0, 0});
    for(int i = 0; i <= 2*n;++i) {
        auto& tmp = mp[dp_mod[i]];
        if (!tmp.empty()) {
            mx = max(mx, dp[i] - mp[dp_mod[i]].begin()->first);
        }
        mp[dp_mod[i]].insert({dp[i], i});
        if (i >= n) {
            mp[dp_mod[i-n]].erase({dp[i-n], i-n});
        }
    }
    return (mx== LLONG_MAX ? -1 : mx);
}
int main() {
    int n; 
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << maxSumOfBeautifulSubarray(a);
}