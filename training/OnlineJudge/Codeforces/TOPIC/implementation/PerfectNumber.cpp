// https://codeforces.com/problemset/problem/919/B
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()
#define FOR(i, a) for (int i = 0; i < (a); ++i)
#define FOR1(i, a) for (int i = 1; i < (a + 1); ++i)
#define F0R(i, a, b) for (int i = (a); i < (b); ++i)
#define F_OR(i, a, b, step) for (int i = (a); (step) > 0 ? i < (b) : i > (b); i += (step))
#define EACH(x, a) for (auto &x : a)
template <class T>
#define IO                                  \
    {                                       \
        freopen("input.txt", "r", stdin);   \
        freopen("output.txt", "w", stdout); \
    }
void print(T &x)
{
    for (auto &it : x)
    {
        cout << it << " ";
    }
    cout << "\n";
};
void solve();
bool check(int n)
{
    int s = 0;
    while (n > 0)
    {
        s += n % 10;
        n /= 10;
    }
    return s == 10;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // IO;
    solve();
}
void solve()
{
    int n;
    cin >> n;
    int j = 1;
    FOR(i, 111111111)
    {
        if (check(i))
        {
            if (n == j)
            {
                cout << i << "\n";
                return;
            }
            else j++;
        }
    }
}