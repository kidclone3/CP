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
int a[5][5];
map<int,pair<int,int>>mp;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    F_OR(i, 0, 3, 1) {
        F_OR(j, 0, 3, 1) {
            cin >>a[i][j];
            mp[a[i][j]]={i,j};
        }
    }
    int t;
    cin >> t;
    // int ans = 0;
    F_OR(i, 0, t, 1) {
        int tmp;
        cin >> tmp;
        if(mp.count(tmp)) a[mp[tmp].first][mp[tmp].second]=-1;
    }
    //check;
    bool check = false;
    F_OR(i, 0, 3, 1) {
        // check doc.
        if (a[i][0] == a[i][1] && a[i][1]==a[i][2] &&a[i][0]==-1) {
            check = true;
            break;
        }
    }
    // check cheo 1
    if (a[0][0]==a[1][1] && a[1][1]==a[2][2] && a[0][0]==-1) {
        check = true;
    }
    // check cheo 2
    if (a[0][2]==a[1][1] && a[1][1]==a[2][0] && a[1][1]==-1) {
        check = true;
    }
    // hang ngang
    F_OR(j, 0, 3, 1) {
        if (a[0][j]==a[1][j] && a[1][j]==a[2][j] && a[2][j]==-1) {
            check = true;
        }
    }
    (check) ? (cout<<"Yes"):(cout<<"No");
}
