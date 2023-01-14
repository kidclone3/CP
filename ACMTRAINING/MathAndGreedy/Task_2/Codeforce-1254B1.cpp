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
template <class T>
void print(T &x)
{
    for (auto &it : x)
    {
        cerr << it << " ";
    }
    cerr << "\n";
};
template <class T>
void printPair(T &x)
{
    for (auto &it : x)
    {
        cerr << "(" << it.first << ", " << it.second <<") ";
    }
    cerr << "\n";
};
int solve() {
    int n; cin >> n;
    vi a(n);
    int sum = 0;
    FOR(n) cin >> a[i], sum += a[i];
    if (sum == 1) return cout << -1, 0;
    // find all divisors of sum;
    vi list_divisors;
    for(int i = 2; i*i <= sum; ++i) {
        if (sum % i == 0) {
            list_divisors.push_back(i);
            if (i != sum / i) {
                list_divisors.push_back(sum/i);
            }
        }
    }
    list_divisors.push_back(sum);
    sort(all(list_divisors));

    // Because of smallest step, so the common number is the minimum in list_divisors.
    ll result = 1e18;
    EACH(common, list_divisors) {
        ll ans = 0LL;
        for(int i = 0, j = 0; i < n;) {
            if (a[i] == 1) {
                vi tmp;
                tmp.push_back(i);
                for(j = i+1; j < n && (int) tmp.size() < common; ++j) {
                    if (a[j] == 1) tmp.push_back(j);
                }
                int median = tmp[tmp.size()/2];
                EACH(it, tmp) {
                    ans += (ll) abs(it - median);
                }
                i = j;
            } else i++;
        }
        result = min(result, ans);
    }
    cout << result;
    return 0;
}
int main() {
    IOS;
#ifndef ONLINE_JUDGE
	freopen("in", "r", stdin);
	freopen("out", "w", stdout);
#else
	// online submission
#endif
    solve();
    return 0; 
}

