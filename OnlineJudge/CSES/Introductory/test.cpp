#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()
#define F_OR(i, a, b, step) for (int i = (a); (step) > 0 ? i < (b) : i > (b); i += (step))
#define EACH(x, a) for (auto &x : a)
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
    int N = 1000;
    // cin >> N;
    // process(0);
    string s="";
    F_OR(i,1, N, 1) {
        s+=to_string(i);
    }
    int n; cin >> n;
    F_OR(i, n-3, n+3, 1) {
        cout<<s[i-1];
    }
    cout<<"\n"<<s[n-1];
}