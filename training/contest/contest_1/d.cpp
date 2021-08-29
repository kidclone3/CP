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
    int n;
    cin >> n;
    map<int, int> mp;
    F_OR(i, 0, n, 1) {
        int tmp;
        cin >> tmp;
        mp[tmp] ++;
    }
    int couple = 0;
    for (auto &it: mp) {
        if (it.second >= 2) {
            if (it.second & 1) {
                it.second = 1;
            }
            else {it.second = 2;
                couple++ ;
            }
        }
    }
    // cout << couple <<'\n';
    int ans = mp.size();
    if (couple&1) ans--;
    cout << ans;
}
