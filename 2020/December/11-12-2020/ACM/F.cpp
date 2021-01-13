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
    string s1,s2;
    int n; cin>>n;
    s1="";
    for(int i=0; i<n; ++i) {
        char ch;
        cin>>ch;
        s1+=ch;
    }
    int count=0;
    s2=s1.substr(1,s1.size()-1);
    s2+='&';
    for(int i=0; i<s1.size(); ++i) {
        if(s1[i]==s2[i]) count++;
    }
    cout<<count;

}