/*
    Code nay duoc go lai tu code cua 1 thanh nien hoc MIT.
    No thien ve DP hon la sort and search.
    Xay dung ham ok de tim xem su thay doi => kha kho de nhan ra dieu nay.
*/
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
const int NM = 2*100000+5;
bool ok[NM]; // Mang ok de luu su thay doi round giua vi tri i va i+1.
             // ok[i] = 0 neu' p[i] va p[i+1] cung` tren 1 round
             // ok[i] = 1 neu' nguoc lai
int a[NM], ans, p[NM], N, M; // mang P de danh dau vi tri.
void check(int x) {
    // Neu x ko thuoc [1, N) => cut' luon.
    if (x<1 || x>=N) return;
    //Bay h la buoc tinh mang ok. Kha' la` kho' luon
    //OK ban dau full 0.
    if (ok[x] != (p[x] > p[x+1])) { // Neu gia tri mang OK != p[x] > p[x+1] ???
    // Phuc vu cho muc dich thay doi gia tri o moi query, ta can` check xem 
    // ok[x] co' thay doi ko (tuc la so' co' thay doi round hay ko).
        ans += (ok[x]^=1)*2 -1;
        // ok[x] ^= 1. Dau ^ la xor, xor chi = 1 neu ca 2 bit deu khac nhau.
        // O day co nghia la thay doi gia tri cua ok[x] => 0 hoac 1
    }
    
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    F_OR(i, 1, N+1, 1) {
        cin >> a[i], p[a[i]] = i;
    }
    // Can tinh ans ban dau, luu nhung vi tri lam doi vong vao mang OK
    ans = 1;
    F_OR(i, 1, N, 1){
        check(i);
    }
    // Sau buoc nay co' the tinh ra ans ban dau :)
    // Den phan duyet queries.
    F_OR(i, 0, M, 1) {
        int u, v;
        cin >> u >> v;
        swap(a[u], a[v]);
        swap(p[a[u]], p[a[v]]);
        // Nhung vi tri co' the thay doi khi thay doi u, v:
        check(a[u]-1); // => vi tri a[u]-1 va a[u]
        check(a[u]);   // => vi tri a[u] va a[u]+1
        check(a[v]-1); // => vi tri a[v]-1 va a[v]
        check(a[v]);   // => vi tri a[v] va a[v]+1.
        // Ok, bay gio thi ans cung da~ duoc doi.
        cout<<ans<<'\n';
    }
}