#include <bits/stdc++.h>
using namespace std;

int solve() {
    string s1, s2;
    cin >> s1 >> s2;
    int overallDiff = 0;
    int oneDiff = 0;
    int numberOneToZero = 0, numberZeroToOne = 0;
    int n = s1.size();
    for(int i = 0; i < n; ++i) {
        if (s1[i]  != s2[i]) 
            ++overallDiff;
        if (s1[i] == '?' && s2[i] == '1') 
            --oneDiff;
        else if (s1[i] == '0' && s2[i] == '1') {
            ++numberZeroToOne;
            --oneDiff;
        } else if (s1[i] == '1' && s2[i] == '0') {
            ++numberOneToZero;
            ++oneDiff;
        }
    }
    if (oneDiff > 0) return -1;
    return overallDiff - min(numberOneToZero, numberZeroToOne);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;
    for(int t = 1; t <= T; ++t) {
        cout << "Case " << t << ": " << solve() << '\n';
    }
}
