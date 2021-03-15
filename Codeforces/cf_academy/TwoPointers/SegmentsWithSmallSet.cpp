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
const int N = 1e5+5;
int a[N], cnt[N], num;
void add(int x) {
    cnt[x]++;
    if (cnt[x] == 1) {
        num++;
    }
}
void remove(int x) {
    cnt[x]--;
    if(cnt[x] == 0) {
        num--;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    F_OR(i, 0, n, 1) {
        cin >> a[i];
    }
    int l=0;
    ll res = 0;
    F_OR(r, 0, n, 1) {
        add(a[r]);
        while(num>k) {
            remove(a[l]);
            l++;
        }
        res+=(ll) r-l+1;
    }
    cout<<res;
}