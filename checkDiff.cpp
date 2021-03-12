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
    int n = 1000;
    int tmp;
    vector<int> vt1, vt2;
    ifstream file1("1.txt"), file2("2.txt");
    F_OR(i, 0, n, 1) {
        int tmp; file1 >> tmp;
        vt1.pb(tmp);
    }
    // print(vt1);
    F_OR(i, 0, n, 1) {
        int tmp; file2 >> tmp;
        vt2.pb(tmp);
    }
    // cout << "\n";
    // print(vt2);
    cout << "line" << " 1" << "  2" <<'\n';
    F_OR(i, 0, n, 1) {
        if (vt1[i] != vt2[i]) {
            cout << i << ": " << vt1[i] << " , " << vt2[i] <<"\n";
        }
    }
}
