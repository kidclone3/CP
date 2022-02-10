#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()
#define FOR(i, a) for (int i = 0; i < (a); ++i) 
#define F0R(i, a, b) for (int i=(a); i < (b); ++i)
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
void solve();
string format(string s) {
    EACH(it, s) {
        if (it < 'a') {
            it += 'a' - 'A';
        }
    }
    return s;
}
string vowels(string s) {
    vector<char> vowel = {'a', 'o', 'e', 'i', 'u', 'y'};
    string ans ="";
    EACH(it, s) {
        bool check = true;
        EACH(j, vowel) {
            if (it == j) {
                check = false;
                break;
            }
        }
        if (check) {
            ans+=".";
            ans+=it;
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    solve();
}
void solve() {
    string s;
    cin >> s;
    s = format(s);
    cout << vowels(s);
}   