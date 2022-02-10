
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
    bitset<10>bt[5];
    F_OR(i, 0, 5, 1) {
        // cout<<bt[i]<<'\n';
        F_OR(j, 0, 10, 1) {
            if (!bt[i][j]) {
                bt[i][j]=1;   
            }
        }
        cout<<bt[i];
        cout<<'\n';
    }
}
