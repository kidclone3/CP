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
const int N = 2*1e5+5;
int a[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    map<int, int> mp;
    F_OR(i, 0, n, 1){
        cin >> a[i];
        mp[a[i]]++;
    }
    int res = 0;
    auto it = mp.begin();
    if (it->first == 1) {
        if (it->second==1) {
            return cout<<1,0;
        }
        else {
            return cout<<0,0;
        }
    }
    set<int> st; // luu nhung phan tu da duyet roi.
    // Vong duyet dinh menh.
    while(it!=mp.end()) {
        if (it->second!=1) {
            it++;
            st.insert(it->first);
            continue;
        }
        // auto j = st.lower_bound(sqrt(it->second));
        bool success = true;
        int x = it->first;
        for(int tmp = 2; tmp*tmp<=it->first; ++tmp) {
            if (x%tmp==0) {
                if (mp[tmp]>=1 || mp[x/tmp] >= 1) {
                    success = false;
                    break;
                }
            }
        }
        if (success) res++;
        st.insert(it->first);
        it++;
    }
    cout<<res;
}
