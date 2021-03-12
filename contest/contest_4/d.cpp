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
    int n, q;
    string s;
    vector<set<int>> vt(26);
    cin >> n >> s >> q;
    // init array of vt;
    // vector<int> locate(s.size());
    // vector<pair<int,pair<int,char>>> queries;
    F_OR(i, 0, s.size(), 1) {
        vt[s[i]-'a'].insert(i);
    }
    F_OR(i, 0, q, 1) {
        // int a,b;
        // char c;
        // cin >> a >> b >> c;
        // queries.pb({a,{b,c}});
        int a, l, r, c;
        char ch;
        cin >> a;
        if (a==1) { // thay doi phan tu.
            cin >> c >> ch;
            c--;
            // auto tmp = vt[s[c]-'a'].lower_bound(c);
            vt[s[c]-'a'].erase(c);
            vt[ch-'a'].insert(c);
            s[c] = ch;
        } 
        else {
            cin >> l >> r;
            int res = 0;
            for(int i = 0; i<= 'z' - 'a'; ++i) {
                auto l1 = vt[i].lower_bound(l-1);
                if (l1!=vt[i].end() && *l1<=(r-1)) {
                    res++;
                }
            }
            cout<<res<<'\n';
        }
    }
}
