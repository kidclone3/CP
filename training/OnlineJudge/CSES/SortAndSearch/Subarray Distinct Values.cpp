#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n, k; cin >> n >> k;
    vector<int> a(n);
    map<int, int> mp;
    ll ans = 0ll;
    int l = 0;
    ll sz = 0LL;
    for(int i = 0; i < n; ++i) {
        cin >> a[i];
        mp[a[i]]++;
        sz++;
        if (mp.size() == k) {
            ans += ;
        }
    }
    cout << ans; 
}
