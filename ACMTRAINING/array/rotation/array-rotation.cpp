#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
#define ar array
#define vt vector
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define ll long long
#define ld long double
#define ii pair<int, int>
#define iii pair<int, ii>
#define vb vt<bool>
#define vc vt<char>
#define vi vt<int>
#define vl vt<ll>
#define vvb vt<vb>
#define vvc vt<vc>
#define vvi vt<vi>
#define vvl vt<vl>
#define vii vt<ii>
#define fi first
#define se second
#define FORIT(i, s) for (auto it=(s.begin()); it!=(s.end()); ++it)
#define F_OR(i, a, b, s) for (int i=(a); (s)>0? i<(int)(b) : i>(int)(b); i+=(s))
#define F_OR1(n) F_OR(i, 0, n, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define FOR1(n) F_OR(i, 1, n+1, 1)
#define EACH(x, a) for(auto& x: a)

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int d4x[] = {-1, 0, 1, 0},
        d4y[] = {0, -1, 0, 1},
        d8x[] = {-1, -1, -1, 0, 0, 1, 1, 1},
        d8y[] = {-1, 0, 1, -1, 1, -1, 0, 1};
template<class T1, class T2> istream &operator >>(istream &cin, pair<T1, T2> &x){
    cin >> x.fi >> x.se;
    return cin;
}

template<class T1, class T2> ostream &operator <<(ostream &cout, pair<T1, T2> x){
    cout << "(" << x.fi << "," << x.se << ")";
    return cout;
}

template<class T> istream &operator >>(istream &cin, vt<T> &v){
    FOR(v.size()) cin >> v[i];
    return cin;
}

ostream &operator <<(ostream &cout, vc &v){
    FOR(v.size()) cout << v[i] << " \n"[i==(int)v.size()-1];
    return cout;
}

ostream &operator <<(ostream &cout, vi &v){
    FOR(v.size()) cout << v[i] << " \n"[i==(int)v.size()-1];
    return cout;
}

ostream &operator <<(ostream &cout, vl &v){
    FOR(v.size()) cout << v[i] << " \n"[i==(int)v.size()-1];
    return cout;
}

template<class T> ostream &operator <<(ostream &cout, const vt<vt<T>> &v){
    FOR(v.size()) FOR(j, v[i].size()) cout << v[i][j] << " \n"[j==v[i].size()-1];
    return cout;
}

int solve() {
    // We will rotate the array.    
    vi a = {1,2,3,4,5,6,7,8};
    int d = 3;
    int n = a.size();
    int gcd = __gcd(n, d);
    FOR(gcd) {
        int temp = a[i];
        int j = i;
        while(1) {
            int k = j + d;
            cout << k << ' ';
            if (k >= n) k-= n;
            if (k == i) break;
            a[j]=a[k];
            j = k;
        }
        a[j] = temp;
        cout << '\n';
    }
    cout << a;
    return 0;
}
int main() {
    IOS;
    solve();
    return 0; 
}

