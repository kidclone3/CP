#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
#define ar array
#define vt vector
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define ll long long
#define ld long double
#define ii pair<int, int>
#define iii pair<int, ii>
#define vb vt<bool>
#define vc vt<char>
#define vi vt<int>
#define vl vt<ll>
#define vvb vt<vb>
#define vvc vt<vc>
#define vvi vt<vi>
#define vvl vt<vl>
#define vii vt<ii>
#define fi first
#define se second
#define FORIT(i, s) for (auto it=(s.begin()); it!=(s.end()); ++it)
#define F_OR(i, a, b, s) for (int i=(a); (s)>0? i<(int)(b) : i>(int)(b); i+=(s))
#define F_OR1(n) F_OR(i, 0, n, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define FOR1(n) F_OR(i, 1, n+1, 1)
#define EACH(x, a) for(auto& x: a)

#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

const int d4x[] = {-1, 0, 1, 0},
        d4y[] = {0, -1, 0, 1},
        d8x[] = {-1, -1, -1, 0, 0, 1, 1, 1},
        d8y[] = {-1, 0, 1, -1, 1, -1, 0, 1};
template <class T>
void print(T &x)
{
    for (auto &it : x)
    {
        cout << it << " ";
    }
    cout << "\n";
};
template <class T>
void printPair(T &x)
{
    for (auto &it : x)
    {
        cout << "(" << it.first << ", " << it.second <<") ";
    }
    cout << "\n";
};
const string aba = "abacaba";

bool acceptable(string &s) {
    FOR(7) if (s[i] == '?' || s[i] == aba[i]) continue; else return false;
    return true;
}

void fillOther(string &s) {
    EACH(it, s) if (it == '?') it = 'z';
}

bool check(string &s) {
    int cnt = 0;
    FOR(i, s.size()-6) {
        string ss = s.substr(i, 7);
        if (acceptable(ss)) cnt++;
    }
    return cnt == 1;
}

int solve() {
    int n; cin >> n;
    string s; cin >> s;
    if (n == 7) {
        if (acceptable(s)) {
            return cout << "Yes\n"<<aba<<'\n', 0;
        }
        else return cout << "No\n",0;
    } else {
        FOR(i, n-6) {
            string ss = s.substr(i, 7);
            if (acceptable(ss)) {
                string s1, s2;
                s1 = s.substr(0, i);
                s2 = s.substr(i+7, n-i);
                fillOther(s1);
                fillOther(s2);
                string s3 = s1+aba+s2;
                if (check(s3)) {
                    cout << "Yes\n";
                    cout << s3 << "\n";
                    return 0;
                }
            }
        }
    }
    cout << "No\n";
    return 0;
}
int main() {
    IOS;
    int t; cin >> t;
    while(t--)
    solve();
    return 0; 
}

