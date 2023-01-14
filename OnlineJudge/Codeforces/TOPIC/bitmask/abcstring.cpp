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
bool check(string s) {
    int n = s.size();
    // Neu s[0] buoc phai la mo, s[n-1] buoc phai dong
    // Mo = 1, dong = 0
    // Neu s[0]==s[1] => sai dau ==> false
    if (s[0] == s[n-1]) return false;
    // tinh 2 cai tong, neu la mo => +1, neu dong => -1
    int tmp1, tmp2;
    tmp1 = tmp2 = 0;
    // chia ra 3 ki tu, a, b, c.
    // a la ki tu s[0], c = s[n-1]. b la cai con lai
    bool right1, right2; // kiem tra xem tmp da am hay chua. Neu am => bo.
    right1 = right2 = 1;
    F_OR(i, 0, n, 1) {
        if(s[i]==s[0]) {
            if(right1) tmp1++;
            if (right2) tmp2++;
        }
        else if (s[i] == s[n-1]) {
            if (right1) tmp1--; 
            if (right2) tmp2--;
            if (tmp1<0) right1=false;
            if (tmp2<0) right2=false;
            
        }
        else {
            if (right1) tmp1++; 
            if (right2) tmp2--;
            if (tmp2<0) right2=false;
        }
        if (!right1 && !right2) return false;
    }
    if (tmp1==0 || tmp2==0) return true;
    return false;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    while(n--) {
        string s;
        cin>> s;
        // if (check(s)) cout<<"YES\n";
        // else cout<<"NO\n";
        check(s)?(cout<<"YES\n") : (cout<<"NO\n");
    }
}
