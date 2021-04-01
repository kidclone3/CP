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
// const int N = 2*1e5+5;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, q;
    cin >> n >> q;
    // de luu rank va nha` tre cua dua tre thu i.
    vector<pair<int, int>> a(n+1);
    // multiset<int> st[2*10^5];
    // Cac nha` tre, dc danh so tu 1->2*1e5;
    map<int, multiset<int>> st;
    //map<ten nha tre, set de luu rank cua cac be' trong nha tre>
    // y tuong: de biet co' nhung nha tre nao da dc xuat hien
    // set<int> kinder;
    F_OR(i, 1, n+1, 1) {
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;
        a[i] = {tmp1, tmp2};
        st[tmp2].insert(tmp1);
        // kinder.insert(tmp2);
    }
    //tim ra max.
    multiset<int> mx;
    EACH(it, st) {
        mx.insert(*it.second.rbegin());
    }
    F_OR(i, 1, q+1, 1) {
        int name, new_addr;
        cin >>name >> new_addr;
        bool did_not_appear = false;
        if (st[new_addr].empty()) did_not_appear = true;
        // can tim dia chi nha tre cu, xoa no' di
        int old_addr = a[name].second; // dia chi cua nha tre cu.
        // truoc khi xoa, can vut gia tri max cua nha tre old_addr di da.
        auto j = mx.lower_bound(*st[old_addr].rbegin());
        mx.erase(j);
        auto it = st[old_addr].lower_bound(a[name].first); // xoa chi so cua dua tre o nha tre cu.
        st[old_addr].erase(it);
        // dua dua tre den nha moi.
        // Neu nha moi xuat hien roi thi can` xoa' no' khoi mx da.
        if (!did_not_appear) {
            auto jj = mx.lower_bound(*st[new_addr].rbegin());
            mx.erase(jj);
        }
        st[new_addr].insert(a[name].first);
        // cap nhat lai dia chi cho dua tre
        a[name] = {a[name].first, new_addr};

        // cap nhat lai luu tru max.
        if (!st[old_addr].empty())
            mx.insert(*st[old_addr].rbegin());
        mx.insert(*st[new_addr].rbegin());
        
        // ok, bay h cout max ra.
        cout<<*mx.begin()<<"\n";
    }
}
