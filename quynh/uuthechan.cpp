#include <bits/stdc++.h>
using namespace std;
void solve() {
    long long n;
    cin >> n;
    int chan, le;
    chan = le = 0;
    while(n>0) {
        if (n%2==0) {
            chan++;
        }
        else{
            le++;
        }
        n/=10;
    }
    (chan>=le) ? (cout<<"YES\n") : (cout<<"NO\n");
}
int main() {
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}