#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()
#define FOR(i, a) for (int i = 0; i < (a); ++i) 
#define F0R(i, a, b) for (int i=(a); i < (b); ++i)
#define F_OR(i, a, b, step) for (int i=(a); (step)>0? i<(b) : i>(b); i+=(step))
#define EACH(x, a) for(auto& x: a)
template <class T>
#define IO                                  \
    {                                       \
        freopen("input.txt", "r", stdin);   \
        freopen("output.txt", "w", stdout); \
    }
void print(T &x)
{
    for (auto &it : x)
    {
        cout << it << " ";
    }
    cout << "\n";
};
void solve();
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // IO;
    solve();
}
void solve() {
    int n, d;
    cin >> n >> d;
    string s;
    cin >> s;
    int i = 0;
    int count = 0;
    for (; i < s.size()-1; ) {
        int j = i+d;
        if (j >= s.size()) {
            count++;
            break;
        }
        while(j > i && s[j] == '0') {
            j--;
        }
        if (i==j) {
            cout << "-1";
            return;
        }
        i = j;
        count++;
    } 
    cout << count;
}