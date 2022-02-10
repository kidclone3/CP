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
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    map<int, int> mp;
    F_OR(i, 0, n, 1) {
        cin >> a[i];
        mp[a[i]]++;
    }
    if (mp.size() == 1) {
        cout<<n<<'\n';
        return;
    }
    vector<int> ans(mp.size());
    int i = 0;
    EACH(it, mp) {
        ans[i++] = it.second;
    }
    sort(all(ans));
    // two pointer :))
    i = 0;
    int j = ans.size()-1;
    while (i != j) {
        if (ans[j] > ans[i]) {
            ans[j] -= ans[i];
            ans[i] = 0;
            i++;
        }
        else if (ans[j] == ans[i]) {
                ans[i] = ans[j] = 0;
                if (j-i > 1) {
                    i++;
                    j--;
                }
                else {
                    i++;
                }
        }
        else {
            int tmp = ans[i] - ans[j];
            while(tmp > 0) {
                j--;
                if (ans[j] < tmp) {
                    tmp-= ans[j];
                    ans[j] = 0;
                }
                else {
                    ans[j] -= tmp;
                }
            }
        }
    }
    cout<<ans[j]<<'\n';
    return;

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
