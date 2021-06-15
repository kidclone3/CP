// https://codeforces.com/problemset/problem/1283/C
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
int main()
{
    IOS;
    solve();
}
void solve() {
    int n;
    cin >> n;
    vector<int> a(n+1, 0), b(n+1, 0), c;
    priority_queue<int> pq1, pq2, pq3;
    FOR1(n) {
        cin >> a[i];
        if (a[i]) b[a[i]] = i;
        else {
            pq1.push(i);
        }
    }   
    c = a;
    FOR1(n) {
        if (!b[i]) {
            pq2.push(i);
        }
    }
    while(!pq1.empty()) {
        if (pq1.top() == pq2.top()) {
            pq3.push(pq1.top());
        }
        else {
            a[pq1.top()] = pq2.top();
            pq2.pop();
        }
        pq1.pop();
    }
    while(!pq3.empty()) {
        a[pq3.top()] = pq2.top();
        pq3.pop();
        pq2.pop();
    }
    stack<int> st1, st2;
    // st1 de luu nhung vi tri da thoa man a[i] != i
    // st2 de luu nhung vi tri bi loi a[i] == i
    FOR1(n) {
        if (c[i] == 0) {
            if (a[i] == i) {
                st2.push(i);
            }
            else {
                st1.push(i);
            }
        }
    }
    // vi luon co st2.size() <= st1.size() nen ta thoai mai.
    while(!st2.empty()) {
        auto it1 = st1.top();
        auto it2 = st2.top();
        swap(a[it1], a[it2]);
        st1.pop(), st2.pop();
    }
    FOR1(n) {
        cout << a[i] << " ";
    }
}
