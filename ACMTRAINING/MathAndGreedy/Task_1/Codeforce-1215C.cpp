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
    string s1, s2;
    cin >> s1 >> s2;
    
    vi diff_a, diff_b;

    FOR(n) if (s1[i] != s2[i]) {
        if (s1[i] == 'a')
            diff_a.push_back(i);
        else diff_b.push_back(i);
    }
    vii ans;
    while (diff_a.size() >= 2) {
        int l = diff_a.back();
        diff_a.pop_back();
        int r = diff_a.back();
        diff_a.pop_back();
        ans.push_back({l, r});
    }
    while (diff_b.size() >= 2) {
        int l = diff_b.back();
        diff_b.pop_back();
        int r = diff_b.back();
        diff_b.pop_back();
        ans.push_back({l, r});
    }
    if (diff_a.size() && diff_b.size()) {
        ans.push_back({diff_b[0], diff_b[0]});
        int l = diff_a[0], r = diff_b[0];
        ans.push_back({l, r});
        diff_b.pop_back();
        diff_a.pop_back(); 
    }
    if (diff_a.empty() && diff_b.empty()) {
        cout << ans.size() <<'\n';
        EACH(it, ans) cout << it.fi+1 << " " << it.se+1<< '\n';
    } else {
        cout << "-1";
    }
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

