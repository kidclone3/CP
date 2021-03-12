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
int N;
string s="";
vector<vector<int>> vt;
void out()
{
    ll tmp=0;
    for(int i=0; i<N; ++i) {
        if (s[i]=='1') {
            tmp^=(i+1);
        }
    }
    if(tmp==N) {
        vi tmp2;
        for(int i=0; i<N; ++i) {
            if(s[i]=='1')
            {
                tmp2.pb(i+1);
            }
        }
        vt.pb(tmp2);
    }
}
void gen(int n)
{
    if (n==N) 
    {
        out(); 
    }
    else 
    {
        for(char i='0'; i<='1'; ++i) {
            s+=i;
            gen(n+1);
            s.pop_back();
        }
    }
    
}
bool cmp(vi v1, vi v2) {
    return v1.size() < v2.size();
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>N;
    gen(0);
    sort(all(vt), cmp);
    for(auto &i:vt)
    {
        for(auto &j:i)
        {
            cout<<j<<" ";
        }
        cout<<"\n";
    }
}