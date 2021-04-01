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
int solve(int *c, int n) {
    int res = 0;
    // // tinh th lien ke truoc
    // if (c[0] > c[1] && c[0] + c[1] == n*2/3) {
    //     return c[0] - n/3;
    // }
    // if (c[1] > c[2] && c[1] + c[2] == n*2/3) {
    //     return c[1] - n/3;
    // }
    // if (c[2] > c[0] && c[2] + c[0] == n*2/3) {
    //     return c[2] - n/3;
    // }
    // // th cach nhau 1
    // if (c[0] > c[2] && c[0] + c[2] == n*2/3) {
    //     return (c[0] - n/3)*2;
    // }
    // if (c[1] > c[0] && c[1] + c[0] == n*2/3) {
    //     return (c[1] - n/3)*2;
    // }
    // if (c[2] > c[1] && c[2] + c[1] == n*2/3) {
    //     return (c[2] - n/3)*2;
    // }
    // th ko lquan den nhau.
    queue<int> q;
    int i = 0;
    while(true) {
        if (!q.empty()) {
            res+=q.back();
            c[i]+=q.back();
            q.pop();
        }
        if (c[i] > n/3) {
            q.push(c[i] - n/3);
            c[i] = n/3;
        }
        if (c[0] == c[1] && c[1] == c[2]) break;
        i = (i + 1) %3 ;
    }
    return res;

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int c[3] = {0}; 
        
        F_OR(i, 0, n, 1) {
            cin >> a[i];
            c[a[i]%3] ++;    
        }
        cout << solve(c, n) <<'\n';
        
    }
}
