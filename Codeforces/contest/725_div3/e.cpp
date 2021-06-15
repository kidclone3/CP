#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()
#define FORIT(i, s) for (auto it=(s.begin()); it!=(s.end()); ++it)
#define F_OR(i, a, b, s) for (int i=(a); (s)>0? i<(b) : i>(b); i+=(s))
#define F_OR1(n) F_OR(i, 0, n, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define FOR1(n) F_OR(i, 1, n+1, 1)
#define EACH(x, a) for(auto& x: a)
#define IO                                  \
    {                                       \
        freopen("input.txt", "r", stdin);   \
        freopen("output.txt", "w", stdout); \
    }
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
template <class T>
void print(T &x)
{
    for (auto &it : x)
    {
        cout << it << " ";
    }
    cout << "\n";
};
void solve();
ll haha(string s) {
    ll ans = 0LL;
    if (s.size() >= 4)
        FOR(z, (int) s.size() - 3) {
            if (s.substr(z, 4) == "haha") {
                ans++;
            }
        }
    return ans;
}
int main()
{
    IOS;
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
}
void solve() {
    int n;
    cin >> n;
    string s;
    map<string, string> mp;
    map<string, ll> mp2;
    getline(cin, s);
    vector<string> a(n);
    FOR(n) {
        getline(cin, a[i]);
    }
    // ll c_last = 0LL;
    auto combine = [&] (string s1, string s2) {
        ll ans = mp2[s1] + mp2[s2];
        string aa = mp[s1], b = mp[s2];
        if (aa.size() >= 3 && b.size() >= 3 && aa.substr(aa.size() -3, 3) == "hah" && b.substr(0, 3) == "aha") {
            ans+=2;
        }
        else if (aa.size() >= 3 && aa.substr((aa.size() - 3), 3) == "hah") {
            if (b[0] == 'a') ans++;
            }
        else if (aa.size() >= 2 && aa.substr(aa.size() - 2, 2) == "ha") {
            if (b.size() >= 2 && b.substr(0, 2) == "ha") ans++;
        }
        else if (aa.back() == 'h') {
            if (b.size() >= 3 && b.substr(0, 3) == "aha") ans++;
        } 
        return ans;
    };
    FOR(n){
        stringstream ss(a[i]);
        string var[7];
        int j = 0;
        while(ss >> var[j++]) {
            // cout << var[j-1] << " ";
        }
        // cout << '\n';
        if (var[1] == ":=") {
            mp[var[0]] = var[2];
            mp2[var[0]] = haha(var[2]);
        }
        else {
            mp2[var[0]] = combine(var[2], var[4]);
            if (mp[var[2]].size() >= 3) {
                if (mp[var[4]].size() >= 3)
                    mp[var[0]] = mp[var[2]].substr(0, 3) + mp[var[4]].substr(mp[var[4]].size() - 3, 3);
                else {
                    mp[var[0]] = mp[var[2]].substr(0, 3) + mp[var[4]];
                }
            }
            else if (mp[var[4]].size() >= 3){
                mp[var[0]] = mp[var[2]] + mp[var[4]].substr(mp[var[4]].size()-3, 3);
            }
            else 
                mp[var[0]] = mp[var[2]] + mp[var[4]];
            // ý tưởng: thay vì đi copy cả mảng to đùng, ta chỉ copy 3 kí tự đầu và cuối của mảng mà thôi.
            // cout << mp2[var[0]] << '\n';
        }   
        if (i == n-1) {
           cout << mp2[var[0]] << '\n'; 
        //    cout << mp[var[2]] << " " << mp2[var[4]] << "\n";
        //    cout << mp[var[0]] << '\n';
        //    cout << haha(mp[var[0]]) << "\n";
        }
    }
    // EACH(it, mp2) {
    //     cout << it.first << " " << it.second << '\n';
    // }
}
