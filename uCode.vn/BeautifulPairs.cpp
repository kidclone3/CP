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
int a[100000+5];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,k;
    cin >> n >> k;
    F_OR(i, 0, n, 1) {
        cin >> a[i];
    }
    int ans = 0;
    multiset<int> storage;
    F_OR(j, 0, n, 1) {
        storage.insert(a[j]);
        int target = k - a[j] * a[j];
        if (target > 0) {
            ans += storage.count(target);
        }  
    }
    cout<<ans;
}