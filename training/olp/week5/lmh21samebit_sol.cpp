#include <bits/stdc++.h>
 
using namespace std;
 
#define endl '\n'
#define vi vector<long long int>
#define ll long long int
#define all(x) x.begin(), x.end()
 
const ll MOD = 1000000000000000009;
const int mod = 1000000007;
 
bool isPrime(ll n)
{
	if (n <= 1)
		return 0;
	if (n <= 3)
		return 1;
	if (n % 2 == 0 || n % 3 == 0)
		return 0;
	for (ll i = 5; i * i <= n; i += 6)
	{
		if (n % i == 0 || n % (i + 2) == 0)
			return 0;
	}
	return 1;
}
 
vi eratosthenes(ll n)
{
	// int N = 1e6;
	vector<bool> snt(n, true);
	vi prime;
	snt[0] = false;
	snt[1] = false;
	for (int i = 2; i * i <= n; i++)
	{
		if (snt[i])
		{
			for (int j = i * i; j <= n; j += i)
				snt[j] = false;
		}
	}
	for (int i = 2; i <= n; i++)
	{
		if (snt[i] == true)
		{
			prime.push_back(i);
		}
	}
	return prime;
}
 
pair<ll, ll> factor(ll n)
{
	ll s = 0;
	while ((n & 1) == 0)
	{
		s++;
		n >>= 1;
	}
	return {s, n};
}
ll pow(ll a, ll d, ll n)
{
	ll result = 1;
	a = a % n;
	while (d > 0)
	{
		if (d & 1)
			result = (result * a) % n;
		d >>= 1;
		a = (a * a) % n;
	}
	return result;
}
bool test_a(ll s, ll d, ll n, ll a)
{
	if (n == a)
		return true;
	ll p = pow(a, d, n);
	if (p == 1)
		return true;
	for (; s > 0; s--)
	{
		if (p == n - 1)
			return true;
		p = p * p % n;
	}
	return false;
}
bool miller(ll n)
{
	if (n < 2)
		return false;
	if ((n & 1) == 0)
		return n == 2;
	ll s, d;
	tie(s, d) = factor(n - 1);
 
	if (n < 1373653)
	{
		return test_a(s, d, n, 2) && test_a(s, d, n, 3);
	}
	else if (n < 4759123141)
	{
		return test_a(s, d, n, 2) && test_a(s, d, n, 7) && test_a(s, d, n, 61);
	}
	else
	{
		return test_a(s, d, n, 2) && test_a(s, d, n, 3) && test_a(s, d, n, 5) && test_a(s, d, n, 7) && test_a(s, d, n, 11) && test_a(s, d, n, 13) && test_a(s, d, n, 17) && test_a(s, d, n, 19) && test_a(s, d, n, 23);
	}
}
 
ll reflective(ll l, ll r, ll s)
{
	long double i = 1;
	long long int ans = 0;
	long double LL = INT64_MIN;
	long double rr = INT64_MAX;
	while (r > i)
	{
		i *= s;
		LL = ceil(l / i);
		rr = floor(r / i);
		ans += rr - LL + 1;
	}
	return ans;
}
 
ll add_modulo(ll a, ll b, ll m) { return ((a + b) % m + m) % m; }
ll multiply_modulo(ll a, ll b, ll m)
{
	ll res = 0;
	for (a %= m, b %= m; b > 0; a = add_modulo(a, a, m), b >>= 1)
		if (b & 1)
			res = add_modulo(res, a, m);
	return res;
}
ll power_modulo(ll p, ll n, ll m)
{
	ll ans = 1LL;
	for (p %= m; n > 0; p = multiply_modulo(p, p, m), n >>= 1)
	{
		if (n & 1)
			ans = multiply_modulo(ans, p, m);
		// p = p*p % m;
	}
	return ans;
}
 
void least_prime_factor()
{
	int lpf[100001] = {0};
	lpf[1] = 1;
	for (int i = 2; i * i <= 100000; i++)
	{
		if (!lpf[i])
		{
			for (int j = i * i; j <= 100000; j += i)
				if (!lpf[j])
					lpf[j] = i;
		}
	}
	for (int i = 2; i <= 100000; i++)
	{
		if (!lpf[i])
			lpf[i] = i;
	}
}
 
ll phi(ll n)
{
	ll res = n;
	for (ll i = 2; i * i <= n; ++i)
	{
		if (n % i == 0)
		{
			while (n % i == 0)
				n /= i;
			res -= res / i;
		}
	}
	if (n > 1)
		res -= res / n;
	return res;
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
 
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int t = 1;
	cin >> t;
	while (t--)
	{
		ll n;
		cin >> n;
		n--;
		ll mod = 123456789 * 6;
		ll ans = pow(2, n + 2, mod);
		ans = add_modulo(ans, -3 - pow(-1, n % 2), mod);
		cout << ans / 6 << endl;
	}
}