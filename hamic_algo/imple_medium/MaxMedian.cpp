#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

void solve();
int main()
{
    IOS;
    solve();
}
void solve() {
    const ll inf = 1e18 + 7;
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; ++i){
        cin >> a[i];
    }
    a.push_back(inf);
    sort(a.begin(), a.end());
    ll med = n/2;
    for (ll i = med; i < n; ++i) {
        if (a[i] + k <= a[i+1] || k < (a[i+1] - a[i]) * (i-med+1)) {
            // Neu nhu so lan k ko du de tang toan bo phan truoc len
            // => in ra ket qua.
            cout << a[i] + k/(i-med + 1);
            // return;
            break;
        }
        else {
            k -= (a[i+1] - a[i]) * (i - med + 1);
            cout << k << '\n';
        }
    }
}
 
//  k = 7;
// 1 2 3 5 6 6 6 oo
// k = 0
// 1 3 5 11 11 11 13
// k = 5
// k =1
// i = 6;