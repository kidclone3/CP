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
template <class T>
void print2(T &x)
{
    for (auto &it : x)
    {
        cout << it.first << " " << it.second << '\n';
    }
    // cout << "\n";
};
vector<pair<int, int>> ans;
void process(int n, int a, int b, int c)
{
    if (n == 1)
    {
        ans.pb({a, c});
        return;
    }
    process(n - 1, a, c, b);
    process(1, a, b, c);
    process(n - 1, b, a, c);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    // Thap HaNoi can dung de quy de giai :((
    process(n, 1, 2, 3);
    cout << ans.size() << "\n";
    print2(ans);
}