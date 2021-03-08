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
int a[2*100000+5], b[2*100000+5], c[2*100000+5];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    F_OR(i, 1, n+1 ,1) {
        cin >> a[i];
        b[a[i]] = i;
    }   
    // cout << m <<"\n";
    // Tao 1 mang de luu so round o tung phan tu. (mang c)
    int init_ans;
    c[1] = 1;
        F_OR(i, 2, n+1, 1){
            if (b[i]<b[i-1]) {
                c[i] = c[i-1] + 1;
            }
            c[i] = c[i-1];
        }
        init_ans = c[n];
    while(m--) {
        int i1,i2; // 2 elements to swapped.
        cin >> i1 >> i2;
        swap(b[a[i1]], b[a[i2]]);    
        if (b[a[i1]] < b[a[i1]-1]) {
            int tmp = b[a[i1]-1] + 1;
            if (tmp != c[a[i1]]){
            }
        }
        cout << init_ans <<"\n";
        swap(a[i1], a[i2]);
        // swap(mymap[a[i1]], mymap[a[i2]]);
    }
}