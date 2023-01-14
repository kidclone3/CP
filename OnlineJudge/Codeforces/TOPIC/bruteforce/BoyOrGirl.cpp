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
    string s;
    cin >>s;
    bool male = false;
    int a[30] = {0};
    EACH(it, s) {
        a[it-'a']=1;
    }
    int ans = 0;
    F_OR(i, 0, 30, 1) {
        ans+=a[i];
    }
    // male = ans&1;
    // cout<<ans;
    if (ans&1) cout<<"IGNORE HIM!";
    else cout<<"CHAT WITH HER!";
}
