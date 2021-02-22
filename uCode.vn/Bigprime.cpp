#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()
#define F_OR(i, a, b, step) for (int i = (a); (step) > 0 ? i < (b) : i > (b); i += (step))
#define EACH(x, a) for (auto &x : a)
#define BUG(x)                    \
    {                             \
        cout << #x << " = " << x; \
    }
template <class T>
void print(T &x)
{
    for (auto &it : x)
    {
        cout << it << " ";
    }
    cout << "\n";
};
vector<ll> a{2, 3, 5, 7, 11, 13, 17};
uint64_t mulmod(uint64_t a, uint64_t b, uint64_t n)
{
    uint64_t r = 0;
    while (b > 0)
    {
        if (b % 2 != 0)
            r = (r + a) % n;
        a = a * 2 % n;
        b = b / 2;
    }
    return r;
}
pair<ll, ll> factor(ll n)
{
    // n is even now
    ll s = 0;
    while (!(n & 1))
    {
        s++;
        n >>= 1;
    }
    return make_pair(s, n);
}
ll powMod(ll a, ll d, ll n)
{
    ll res;
    if (d == 1)
        return a % n;
    ll tmp = powMod(a, d >> 1, n) % n;
    if (d & 1)
    {
        res = mulmod(mulmod(tmp, tmp, n), a, n);
    }
    else
    {
        res = mulmod(tmp, tmp, n);
    }
    // cout << res << "\n";
    return res % n;
}
bool isPrime(ll n, ll s, ll d, ll a)
{
    if (!(n & 1))
        return false;
    if (n == a)
        return true;

    ll p = powMod(a, d, n);
    if (p == 1)
        return true;
    while (s--)
    {
        if (p == n - 1)
        {
            return true;
        }
        p = mulmod(p, p, n);
    }
    return false;
}
ll solve(ll n)
{
    if (!(n & 1))
        n++;
    while (true)
    {
        ll s, d;
        tie(s, d) = factor(n - 1);
        EACH(i, a)
        {
            if (isPrime(n, s, d, i))
            {
                return n;
            }
        }
        n += 2;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n;
    cin >> n;
    // isPrime ==> Kiem tra nguyen to.
    cout << solve(n);
}