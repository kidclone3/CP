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
int a[2*100000+5], b[2*100000+5];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    for (int i=1; i<=n; ++i) {
        cin>>a[i];
        if (a[i]>a[i-1]) b[i]=i-1;
        else {
            int temp=b[i-1];
            while (a[i]<=a[temp]) temp=b[temp];
            b[i]=temp;
        }
    }
    for (int i=1; i<=n; ++i) {
        cout<<b[i]<<" ";
    }
}