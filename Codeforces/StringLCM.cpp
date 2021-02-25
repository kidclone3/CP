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
int gcd(int a, int b) {
    if (b==0) {
        return a;
    }
    return gcd(b, a%b);
}
pair<string, int> encrypt(string a) {
    for (int i = 1; i<= a.size(); ++i) {
        bool failed = false;
        string tmp = a.substr(0, i);
        for (int j = i; j<a.size()-i+1; j+=i) {
            string tmp2 = a.substr(j, i);
            if (tmp != tmp2) {
                failed = true;
                break;
            }
        }
        if (!failed) {
            return make_pair(tmp, a.size()/i);
        }
    }
    return make_pair(a, 1);
}
string solve(string a, string b){
    string a1, b1;
    int a2, b2;
    tie(a1, a2) = encrypt(a);
    tie(b1, b2) = encrypt(b);
    if (a1 != b1){
        return "-1";
    }
    int lcm = a2*b2 / gcd(a2, b2);
    string tmp = "";
    while (lcm--) {
        tmp+=a1;
    }
    return tmp;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int q;
    cin >> q;
    while (q--) {
        string a, b;
        cin >> a >> b;
        cout<<solve(a, b) << "\n";
    }
}