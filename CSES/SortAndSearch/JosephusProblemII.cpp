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
template <class Iter>
Iter Next(Iter it) {
    return ++it;
};
void check(int &k, int n) {
    if ((k-1)>=n) {
        k= (k-1) %n;
        k++;
    }

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    set<int> st;
    F_OR(i, 1, n+1, 1) {
        st.insert(i);
    }
    // Neu k = 0 => out luon
    if (k == 0) {
        print(st);
        return 0;
    } 
    // neu k to qua => format k.
    check(k, st.size());
    auto it = st.begin();
    // can nhay len truoc k-1 vi tri;
    int tmp = k;
    while(tmp--) {
        if (Next(it) == st.end()) it = st.begin();
        else it++;
    }
    while(st.size()>1) {
        cout<<*it<<" ";
        // Sau khi cout, can xoa ra khoi set.
        auto tmp = it;
        // check xem tmp co' phai cuoi cung ko.
        if (Next(it) == st.end()) tmp = st.begin();
        else tmp++;
        st.erase(it);
        it = tmp;
        int j = k;
        while(j--) {
            // check xem size co = 1 ko
            if (st.size() == 1) break;
            // can check xem truoc it 1 va 2 vi tri co' phai st.end ko.
            if (Next(it) == st.end()) {
                it = st.begin();
            }
            else it++;
        }
    }
    print(st);
}
