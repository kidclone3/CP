#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        long long sum = 0LL;
        for(int i = 0; i < n; ++i) {
            sum += nums[i];
            dp[i] = sum;
            
        }
        long long mx = sum/n;
        int idx = n-1;
        
        for(int i = 0; i < n-1; ++i) {
            long long tmp = abs(dp[i]/(i+1) - (sum-dp[i])/(n-i-1));
            // cout << tmp << ' ';
            if (tmp < mx) {
                mx = tmp;
                idx = i;
            }
            if (tmp == mx) idx = min(idx, i);
        }
        
        return idx;
    }
};

int main() {
    int n = 100000;
    vector<int> a(n);
    for(int i = 0; i < n; ++i) {
        a[i] = 100000;
    }
    a[99998] = 0;
    Solution tmp;
    cout << tmp.minimumAverageDifference(a);
}