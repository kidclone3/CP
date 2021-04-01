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
bool check(string s) {
    int n = s.size();
    for(int i = 0, j = n-1; i<n; i++, j--) {
        if (s[i]!=s[j]) return false;
        // return true;
    }
    for(int i = 0, j = (n-1)/2-1; i<(n-1)/2; i++, j--) {
        if (s[i]!= s[j]) return false;
    }
    for(int i = (n+3)/2-1, j=n-1; i<n; i++, j--) {
        if (s[i]!= s[j]) return false;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    cin >> s;
    if (check(s)) cout<<"Yes";
    else cout<<"No";

}
