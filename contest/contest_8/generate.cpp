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
        cout << it << ", ";
    }
    cout << "\n";
};
const int N = 123456789+1;
int check(int x) {
    vi c(10, 0);
    int sum = 0;
    while(x>0) {
        c[x%10] ++;
        sum+=x%10;
        if (c[x%10] >1) return -1;
        x/=10;
    }
    return sum;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "r", stdin);
    vector<int> vt(51, -1);
    F_OR(i, 1, N, 1) {
        if (check(i)!=-1 && vt[check(i)] == -1) 
            // vt[check(i)] = min(vt[check(i)], i);
            vt[check(i)] = i;
    }
    print(vt);
}
