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
int c[1000], a[1000];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int x, n;
    cin >> x >> n;
    F_OR(i, 0, n, 1) {
        cin >> a[i];
        c[a[i]] = 1;
    }
    if (c[x] == 0) {
        return cout<<x, 0;
    }
    else {
        int l, r;
        int res1, res2;
        int tmp1, tmp2; // save x location.
        l = r = 0;
        tmp1 = tmp2 = x;
        // Find in the left.
        while(tmp1 >= 1 && c[tmp1]) {
            tmp1--;
            l++;
        }
        while(tmp2<=100 && c[tmp2]) {
            tmp2++;
            r++;
        }
        if (l<=r) {
            return cout<<tmp1, 0;
        }
        else {
            cout<< tmp2;
        }
        
    }
}
