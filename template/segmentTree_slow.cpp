const int N = 2*1e5+5;
const int S = 1<<18;
int n, q;
vl arr;

struct node {
    ll sum, pref;
    node(ll _sum, ll _pref) : sum(_sum), pref(_pref) {}
    node(ll x = 0): sum(x), pref(max(0LL, x)) {}
    friend node operator+ (const node &a, const node&b) {
        return {a.sum + b.sum, max(a.pref, a.sum + b.pref)};
    }
} T[S<<1];

void build(int k = 1, int l = 0, int r = n-1) {
    if (l == r) {T[k] = node(arr[l]); return;}
    int m = (l+r)>>1;
    build(k<<1, l, m);
    build(k<<1|1, m+1, r);
    T[k] = T[k<<1] + T[k<<1|1];
}

void update(int p, ll val, int k= 1, int l = 0, int r = n-1) {
    if (l == r) {
        T[k] = node(val); return;
    }
    int m = (l+r)>>1;
    if (p <= m) update(p, val, k<<1, l, m);
    else update(p, val, k<<1|1, m+1, r);
    T[k] = T[k<<1] + T[k<<1|1];
}

node query(int ql, int qr, int k = 1, int l=0, int r=n-1) {
    if (ql > r || l > qr) return 0;
    if (ql <= l && r <= qr) return T[k];
    int m = (l+r)/2;
    node q1 = query(ql, qr, k<<1, l, m);
    node q2 = query(ql, qr, k<<1|1, m+1, r);
    return q1+q2;
}

int solve() {
    cin >> n >> q;
    // vl arr(n);
    arr.resize(n);
    FOR(n) {
        cin >> arr[i];
    }
    build();
}