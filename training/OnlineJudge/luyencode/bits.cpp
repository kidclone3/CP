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

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    bitset<30> bt1(a), bt2(b);
    string aa,bb;
    aa = bt1.to_string();
    bb = bt2.to_string();
    int ans = 0;
    F_OR(i, 0, aa.size(), 1) {
        if (aa[i] != bb[i]) ans++;
    }
    cout<<ans;
}
