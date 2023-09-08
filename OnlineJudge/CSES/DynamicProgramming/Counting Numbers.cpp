#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll dp[20][11][2][2];
vector<int> num;

ll call(int n, int prev_digit, bool leading_zero, bool tight) {
	if (n == 0) return 1;

	// if subproblem is solved;
	if (prev_digit != -1 && dp[n][prev_digit][leading_zero][tight] != -1) 
		return dp[n][prev_digit][leading_zero][tight];
	
	int bound = tight ? num[num.size() - n] : 9;

	ll ans = 0;
	for(int digit = 0; digit <= bound; ++digit) {
		// if leading zero so not consider 
		if (digit == prev_digit && leading_zero == 0) continue;

		ans += call(n-1, digit, (leading_zero && digit == 0), (tight && (digit == bound)));
	}

	return dp[n][prev_digit][leading_zero][tight] = ans;
}

ll solve(ll a) {
	// cout << a << '\n';
	memset(dp, -1, sizeof dp);
	num.clear();

	while(a) {
		num.push_back(a%10);
		a /= 10;
	}
	reverse(num.begin(), num.end());
	ll res = call(num.size(), -1, 1, 1);
	return res;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll a, b; cin >> a >> b;
	ll ans = 0ll;
	ans = solve(b) - solve(a-1);
	// vector<ll> tmp;
	// while(b > a) {
	// 	tmp.push_back(b);
	// 	b /= 10;
	// }
	// tmp.push_back(a-1);
	// reverse(tmp.begin(), tmp.end());
	// for(int i = 0; i < tmp.size()-1; ++i) {
	// 	ans += solve(tmp[i+1]-1) - solve(tmp[i]);
	// }
	// ans += solve(tmp.back()) - solve(tmp.back()-1);
	cout << ans;
}
