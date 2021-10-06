// https://leetcode.com/problems/find-xor-sum-of-all-pairs-bitwise-and/
#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<int> arr1, arr2;
    arr1 = {12};
    arr2 = {4};
    long long ans = 0;
    const int N = 100;
    vector<int> dp1(N, 0), dp2(N, 0);
    // first for 0; second for 1
    for (int j = 0; j <= 32; ++j) {
        for(int i = 0; i < (int) arr1.size(); ++i) {
            if (arr1[i] & (1<<j)) dp1[j]++;
            
        }
        for(int i = 0; i < (int) arr2.size(); ++i) {
            if (arr2[i] & (1<<j)) dp2[j]++;
            
        }
        int one = dp1[j] * dp2[j];
        if (one & 1) {
            ans += (long long) 1 << j;
        }
    }
    // cout << dp1[2];
    cout << ans;
}