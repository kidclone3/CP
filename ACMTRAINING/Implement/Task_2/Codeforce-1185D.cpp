#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

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
#define FORIT(i, s) for (auto it = (s.begin()); it != (s.end()); ++it)
#define F_OR(i, a, b, s) for (int i = (a); (s) > 0 ? i < (int)(b) : i > (int)(b); i += (s))
#define F_OR1(n) F_OR(i, 0, n, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...)       \
	F_ORC(__VA_ARGS__) \
	(__VA_ARGS__)
#define FOR1(n) F_OR(i, 1, n + 1, 1)
#define EACH(x, a) for (auto &x : a)

#define IOS                       \
	ios_base::sync_with_stdio(0); \
	cin.tie(0);                   \
	cout.tie(0);

const int d4x[] = {-1, 0, 1, 0},
		  d4y[] = {0, -1, 0, 1},
		  d8x[] = {-1, -1, -1, 0, 0, 1, 1, 1},
		  d8y[] = {-1, 0, 1, -1, 1, -1, 0, 1};

template <class T>
void print(T &x)
{
    for (auto &it : x)
    {
        cout << it << " ";
    }
    cout << "\n";
};
template <class T>
void printPair(T &x)
{
    for (auto &it : x)
    {
        cout << "(" << it.first << ", " << it.second <<") ";
    }
    cout << "\n";
};
bool check(vii &a, int pos, int dis) {
	int left = 0;
	FOR(i, 1, a.size()) {
		if (left == pos) left++;
		if (i != pos) {
			if (a[i].fi - a[left].fi != dis) return false;
			left++;
		}
	}
	return true;
}
bool check2(vii &a, int pos) {
	vii b;
	FOR(a.size()) if (i != pos) b.push_back(a[i]);
	int dis = b[1].fi - b[0].fi;
	FOR(i, 1, b.size()) if (b[i].fi - b[i-1].fi != dis) return false;
	return true;
}
int elimination(vii &a)
{
	int n = a.size();
	if (n <= 2)
		return 1;
	// Ktra xem co' phai tat ca cac ptu deu nhu nhau ko?
	if (check2(a, 0)) return a[0].se+1;
	// Ktra ptu thu 2 xem co dc ko 
	if (check2(a, 1)) return a[1].se+1;
	// Neu ko phai => do dai da duoc co dinh.

	int dis = a[1].fi - a[0].fi;
	FOR(i, 1, n) {
		if (a[i].fi - a[i-1].fi != dis) {
			if (check(a, i, dis)) {
				return a[i].se+1;
			}
		} 
	}	
	return -1;
}

int solve()
{
	int n;
	cin >> n;
	vii a(n);
	FOR(n)
	cin >> a[i].first, a[i].second = i;
	sort(all(a));
	int ans = elimination(a);
	if (ans != -1)
		return cout << ans, 0;
	cout << -1;
	return 0;
}
int main()
{
	IOS;
	solve();
	return 0;
}
