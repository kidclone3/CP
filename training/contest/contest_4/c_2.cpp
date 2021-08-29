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
int a[10], s[10], ss[10];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    // format array a.
    F_OR(i, 0, m, 1) {
        cin>>s[i] >> ss[i];
    }
    F_OR(i, 0, 1001, 1) {
        string p= to_string(i);
        if (p.size()<n) continue;
        bool check = true;
        F_OR(j, 0, m, 1) {
            if (p[s[j]-1] != ss[j]+'0') {
                // continue;
                check = false;
                break;
            }
        }
        if (check)
            return cout<<i, 0;
        // return 0;
    }
    cout<<"-1";
}