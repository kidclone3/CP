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
    cin >> s;
    vector<vector<char>> numpad;
    string a = "abcdefghijklmnopqrstuvwxyz";
    F_OR(i, 0, a.length(), 3) {
        if (i/3 ==5 || i/3 == 7) {
         numpad.pb({a[i], a[i+1], a[i+2], a[i+3]});
         i++;
        }
        else numpad.pb({a[i], a[i+1], a[i+2]});
    }
    // numpad[numpad.size() - 1].pb('z');
    // EACH(it, numpad) {
    //     print(it);
    // }
    int last = -1;
    int ans = 0;
    EACH(it, s) {
        int now;
        bool isFound = false;
        int count = 0;
        F_OR(i, 0, numpad.size(), 1) {
            F_OR(j, 0, numpad[i].size(), 1){
                if (numpad[i][j] == it) {
                    now = i;
                    isFound = true;
                    count = j+1;
                    break;
                }
            }
            if (isFound) break;
        }
        // cout << now << " ";
        if (now == last) {
            ans+=2;
        }
        ans += count;
        last = now;
    }
    cout << ans;
}
