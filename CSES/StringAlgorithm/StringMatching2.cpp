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
    string n, m;
    cin >> n >> m;
    vector<int> firstChar;
    F_OR(i, 0, n.size()- m.size() + 1, 1) {
        if (n[i] == m[0]) {
            firstChar.pb(i);
        }
    }
    int count = 0;
    EACH(it, firstChar) {
        if (m==n.substr(it, m.size())) count++;
    }
    cout << count;
    
}