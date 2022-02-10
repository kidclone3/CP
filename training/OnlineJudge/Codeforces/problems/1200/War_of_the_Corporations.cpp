// https://codeforces.com/contest/625/problem/esadsad
#include<bits/stdc++.h>
using namespace std;
int main() {
    string s, a;
    cin >>s >> a;
    int n = s.size(), m = a.size();
    int ans = 0;
    for(int i = 0 ; i < (int) n-m+1; ++i) {
        if (s[i] == a[0]) {
            string s1 = s.substr(i, m);
            if (s1 == a) {
                i += m-1;
                ans++;
            }
        }
    }
    cout << ans;
}