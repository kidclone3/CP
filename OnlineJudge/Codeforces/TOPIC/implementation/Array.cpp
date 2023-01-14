// https://codeforces.com/problemset/problem/300/A
#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()
#define FOR(i, a) for (int i = 0; i < (a); ++i) 
#define FOR1(i, a) for (int i = 1; i < (a+1); ++i) 
#define F0R(i, a, b) for (int i=(a); i < (b); ++i)
#define F_OR(i, a, b, step) for (int i=(a); (step)>0? i<(b) : i>(b); i+=(step))
#define EACH(x, a) for(auto& x: a)
template <class T>
#define IO                                  \
    {                                       \
        freopen("input.txt", "r", stdin);   \
        freopen("output.txt", "w", stdout); \
    }
void print(T &x)
{
    for (auto &it : x)
    {
        cout << it << " ";
    }
    cout << "\n";
};
void solve();
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}
void solve() {
    int n;
    cin >> n;
    int a[n];
    multiset<int> positive, negative, zero;
    FOR(i, n) {
        cin >> a[i];
        if (a[i] == 0) zero.insert(0);
        else if (a[i] > 0) positive.insert(a[i]);
        else negative.insert(a[i]);
    } 
    if (negative.size() % 2 == 0) {
        zero.insert(*negative.begin());
        negative.erase(negative.begin());
    }
    if (positive.empty()) {
        if (negative.size() > 2) {
            positive.insert(*negative.begin());
            negative.erase(negative.begin());
            positive.insert(*negative.begin());
            negative.erase(negative.begin());
        }
    }
    cout << negative.size() << " ";
    print(negative);
    cout << positive.size() << " ";
    print(positive);
    cout << zero.size() << " ";
    print(zero);
}
    