
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
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vi a(n);
        map<int, int> mp1, mp2;
        // mp1 de dem xem cac phan tu xuat hien bao nhieu lan
        // mp2 de xem cac phan tu trong mp2 xuat hien bao nhieu lan.
        F_OR(i, 0, n, 1) {
            cin >> a[i];
            mp1[a[i]]++;
        }
        EACH(it, mp1) {
            mp2[it.second]++;
        }
        // tim max cua mp2,
        ll res = LLONG_MAX;
        // y' tuong:
        EACH(it, mp2) {
            ll tmp = 0;
            EACH(j, mp2) {
                if (j.first < it.first) tmp += j.first*j.second;
                if (j.first > it.first) tmp += (j.first - it.first) * j.second;
            }
            res = min(res, tmp);
        }
        
        cout<<res<<"\n";
        
    }
    
}
