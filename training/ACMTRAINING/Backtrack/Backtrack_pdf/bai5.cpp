#include <bits/stdc++.h>
using namespace std;

#define ll long long
int n;
vector<ll> a;


int main() {
    cin >> n;
    a.resize(n);
    ll sum1 = 0LL;
    for(int i = 0; i < n; ++i) cin >> a[i], sum1+=a[i];
    // Dung set + bitwise cho ez.
    set<ll> st; // luu cac so khac nhau.
    for(int i = 1; i < (1<<n); ++i) {
        ll sum = 0LL;
        for(int k = 0; (1<<k) <= i; ++k) {
            if ((i >> k) & 1) {
                sum += a[k];
            }
        }
        st.insert(sum);
    }
    // for (auto it : st) cout << it << "\n";
    for(int i = 1; i <= sum1+1; ++i) if (st.find(i) == st.end()) {
        return cout << i << "\n", 0;
    }
    return 0;
}