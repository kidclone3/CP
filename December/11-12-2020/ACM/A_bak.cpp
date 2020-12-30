#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()
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
    int n;
    cin>>n;
    bitset<8> m(n);
    int k=0;
    for(int i=1; i<=n; ++i) {
        k^=i;
    }
    bitset<8> kk(k);
    cout<<kk<<" "<<k<<"\n";
    cout<<m;
}