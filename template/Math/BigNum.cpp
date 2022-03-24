#include<bits/stdc++.h>

using namespace std;

#define vt vector
#define pb push_back
#define ll long long
#define vi vt<int>
#define FORIT(i, s) for (auto it=(s.begin()); it!=(s.end()); ++it)
#define F_OR(i, a, b, s) for (int i=(a); (s)>0? i<(b) : i>(b); i+=(s))
#define F_OR1(n) F_OR(i, 0, n, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define EACH(x, a) for(auto& x: a)

/*
    Treat BigNum as a vector<int>, char from _size-1 -> 0.
    BASE: each character of BigNum is a integer in range [0, BASE).
*/
const int BASE = 1e5;

void fix(vi &x){
    /*
        fix to the right form after operator 
    */
    x.pb(0);
    FOR(x.size()-1){
        x[i+1] += x[i]/BASE;
        x[i] %= BASE;
        if (x[i]<0) x[i]+=BASE, --x[i+1];
    }
    while(x.size()>1 && !x.back()) x.pop_back();
}

vi operator + (vi x, const vi &y){
    x.resize(max(x.size(), y.size()));
    FOR(y.size()) x[i] += y[i];
    return fix(x), x;
}

vi operator - (vi x, const vi &y){
    x.resize(max(x.size(), y.size()));
    FOR(y.size()) x[i] -= y[i];
    return fix(x), x;
}

vi operator * (vi x, int k){
    assert(k<BASE);
    EACH(xi, x) xi *= k;
    return fix(x), x;
}

vi operator * (const vi &x, const vi &y){
    vi z(x.size()+y.size()+1);
    FOR(x.size()) FOR(j, y.size()){
        z[i+j] += x[i]*y[j];
        z[i+j+1] += z[i+j]/BASE;
        z[i+j] %= BASE;
    }
    return fix(z), z;
}

vi operator / (vi x, int k){
    assert(k<BASE);
    for(int i=x.size()-1, r=0; i>=0; --i) r=r*BASE+x[i], x[i]=r/k;
    return fix(x), x;
}

bool operator < (const vi &x, const vi &y){
    if (x.size()!=y.size()) return x.size()<y.size();
    FOR(i, x.size()-1, -1, -1) if (x[i]!=y[i]) return x[i]<y[i];
    return false; 
}

istream &operator>>(istream &cin, vi &a) {
    string s;
    cin >> s;
    a.clear();
    a.resize(s.size()/4+1);
    FOR(s.size()){
        int x = (s.size()-1-i)/4;  // <- log10(BASE)=4
        a[x] = a[x]*10+(s[i]-'0');
    }
    return fix(a), cin;
}

ostream &operator<<(ostream &cout, const vi &a) {
    printf("%d", a.back());
    FOR(i, a.size()-2, -1, -1) printf("%04d", a[i]);
    return cout;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);
}