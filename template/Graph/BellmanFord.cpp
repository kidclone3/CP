#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ar array
#define vt vector
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define ll long long
#define ld long double
#define ii pair<int, int>
#define iii pair<int, ii>
#define fi first
#define se second
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

const int d4x[] = {-1, 0, 1, 0},
          d4y[] = {0, -1, 0, 1},
          d8x[] = {-1, -1, -1, 0, 0, 1, 1, 1},
          d8y[] = {-1, 0, 1, -1, 1, -1, 0, 1},
          N = 2e5+1;
const ll oo = LLONG_MAX;
int n, // number of vertices 
    m, // number of edges
    s, // start vertex
    e; // end vertex
vt<vt<ii>> G; // adjancency list of edge, G is directed weighted graph
ll d[N]; // distance from s_v to e_v

void bellmanFord(vt<vt<ii>> G){
    fill_n(d, sizeof(d)/sizeof(d[0]), oo);
    d[s]=0;
    FOR(u, 1, n+1){
        EACH(e, G[u]){
            int v(e.se), uv(e.fi);
            d[v]=min(d[v], d[u]+uv);
        }
    }
    FOR(u, 1, n+1){
        EACH(e, G[u]){
            int v(e.se), uv(e.fi);
            if (d[v]>d[u]+uv) d[v]=-oo; // v is in a negative cycle
        }
    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    cin >> n >> m;
    G = vt<vt<ii>>(n+1);
    FOR(m){
        int u, v, w;
        cin >> u >> v >> w;
        G[u].pb(ii(w, v));
    }
    cin >> s >> e;
    bellmanFord(G);
    cout << d[e];
}