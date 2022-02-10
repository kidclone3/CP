#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()
#define F_OR(i, a, b, step) for (int i=(a); (step)>0? i<(b) : i>(b); i+=(step))
#define EACH(x, a) for(auto& x: a)
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
ll gcd (ll a, ll b) {
    if (b==0) return a;
    return (gcd(b, a%b));
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    // numberator: Tu so
    // denominator: Mau so
    ll numberator, denominator;
    numberator = a * d + b * c;
    denominator = b * d;
    ll div = gcd(max(numberator, denominator), min(numberator, denominator));
    numberator /= div;
    denominator /=div;
    cout << numberator << " " << denominator;
}