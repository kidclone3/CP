#include <bits/stdc++.h>
using namespace std;
 
#define pb push_back
#define vi vector<ll>
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
    // freopen("room.inp", "r", stdin);
    // freopen("room.out", "w", stdout);
    ll n;
    cin>>n;
    multiset<tuple<ll,ll,ll>> st;
    vi out;
    out.resize(n);
    for (int i=0 ; i<n; ++i) {
        ll f,s;
        cin>>f>>s;
        st.insert({f,s,i});
        
    }
    multiset<pair<ll,int>>room;
    for(auto &it:st)
    {
        ll f=get<0>(it);    // first
        ll s=get<1>(it);    // second
        ll l=get<2>(it);    // locate
        if(room.empty())
        {
            room.insert({s,1});
            out[l]=1;
        }
        else
        {
            
            auto i=room.lower_bound({f,-1});
            if (i==room.begin() )
            {
                // neu co phong trung thoi gian va be nhat 
                int last=room.size();
                room.insert({s,last+1});
                out[l]=last+1;
            }
            else
            {
                --i;
                int locate=i->second;
                room.erase(i);
                room.insert({s,locate});
                out[l]=locate;
            }   
        }
    }
    cout<<room.size()<<"\n";
    print(out);    
}