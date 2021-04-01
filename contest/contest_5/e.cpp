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
bool a[1005][1005];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int h, w, k;
    cin >> h >> w >> k;
    int cnt = 0;
    F_OR(i, 1, h+1, 1) {
        string s;
        cin >> s;
        F_OR(j, 0, w, 1) {
            if (s[i] == '1') {
                a[i][j+1]=1;
                cnt++;
            }
        }
    }
    // Check xem. Neu so tong so <= k => cout 0;
    if (cnt<=k) return cout<<0, 0;
    // check hang/ cot => neu hang hoac cot o canh <=k => cout 1;
    // CHeck hang tren cung.
    {
        int cnt1 = 0;
        F_OR(i, 1, w+1, 1) {
            if (a[1][i]) cnt1++;
        }
        if (cnt1<=k) return cout<<1, 0;
    }
    // CHeck hang duoi cung.
    {
        int cnt1 = 0;
        F_OR(i, 1, w+1, 1) {
            if (a[h][i]) cnt1++;
        }
        if (cnt1<=k) return cout<<1, 0;
    }
    // check cot ngoai cung ben trai
    {
        int cnt1 = 0;
        F_OR(i, 1, h+1, 1) {
            if (a[i][1]) cnt1++;
        }
        if (cnt1<=k) return cout<<1,0;
    }
    // check cot ngoai cung ben phai
    {
        int cnt1 = 0;
        F_OR(i, 1, h+1, 1) {
            if (a[h][1]) cnt1++;
        }
        if (cnt1<=k) return cout<<1,0;
    }
    // check cac truong hop cout<<2.
        // th1: 1 diem trong 4 goc.
    if (a[1][1] || a[1][w] || a[h][1] || a[h][w]) return cout<<2,0;
        // th2: tong hang / cot <=k.
    {
        // Check tung hang.
        F_OR(i, 2, h, 1) {
            int cnt1 = 0;
            F_OR(j, 1, w+1, 1) {
                if (a[i][j]) cnt1++;
            }
            if (cnt1<=k) return cout<<2,0;
        }
        // check theo cot.
        F_OR(j, 2, w, 1) {
            int cnt1 = 0;
            F_OR(i, 1, h+1, 1) {
                if (a[i][j]) cnt1++;
            }
            if (cnt1<=k) return cout<<2,0;
        }
    }
    // check cout<<3;
        // th1: o cac canh.
        int cnt2 = 0;
        F_OR(i, 2, h, 1) {
            if (a[i][1] || a[i][w]) cnt2++;
        }
        F_OR(j, 2, w, 1) {
            if (a[1][j] || a[h][j]) cnt2++;
        }
        if (cnt2) return cout<<3,0;
    // con lai la cout 4;
    cout<<4;
}
