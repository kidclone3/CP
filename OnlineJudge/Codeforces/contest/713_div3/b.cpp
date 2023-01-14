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
bool vuong(vector<pair<int, int>> vt, int i3, int j3) {
    int ii1 = i3 - vt[0].first;
    int jj1 = j3 - vt[0].second;
    int ii2 = vt[0].first - vt[1].first;
    int jj2 = vt[0].second - vt[1].second;
    return ii1*ii2 + jj1*jj2 == 0;
}
void solve() {
    int n;
    cin >> n;
    char a[n+1][n+1];
    vector<pair<int, int>> vt;
    F_OR(i, 1, n+1, 1) {
        F_OR(j, 1, n+1, 1) {
            cin >> a[i][j];
            if (a[i][j] == '*') {
                vt.pb({i, j});
            }
        }
    }
    // EACH(it, vt) {
    //     cout<<it.first <<' ' <<it.second <<'\n';
    // }
    if (vt[0].first != vt[1].first && vt[0].second != vt[1].second) {
        a[vt[0].first][vt[1].second] = '*';
        a[vt[1].first][vt[0].second] = '*';
        F_OR(i, 1, n+1, 1) {
            F_OR(j, 1, n+1, 1) {
                cout<<a[i][j];
            }
            cout<<'\n';
        }
        return;
    }
    bool br = false;
    F_OR(i, 1, n+1, 1) {
        if (br) break;
        F_OR(j, 1, n+1, 1) {
            if (a[i][j] == '.' && vuong(vt, i, j)) {
                a[i][j] = '*';
                vt.pb({i, j});
                if (vt[0].first != vt[1].first && vt[0].second != vt[1].second) {
                    a[vt[0].first][vt[1].second] = '*';
                    a[vt[1].first][vt[0].second] = '*';  
                    br = true;   
                    break;       
                }
                else {
                    if (vt[1].first != vt[2].first && vt[1].second != vt[2].second) {
                    a[vt[1].first][vt[2].second] = '*';
                    a[vt[2].first][vt[1].second] = '*';  
                    br = true;
                    break;
                    }
                    if (vt[0].first != vt[2]. first && vt[0].second == vt[2].second) {
                    a[vt[0].first][vt[2].second] = '*';
                    a[vt[2].first][vt[0].second] = '*';  
                    br =true;
                    break;
                    }
                }
            }
        }
    }
    F_OR(i, 1, n+1, 1) {
        F_OR(j, 1, n+1, 1) {
            cout<<a[i][j];
        }
        cout<<'\n';
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
