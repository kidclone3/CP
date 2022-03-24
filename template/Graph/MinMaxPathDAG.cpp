
const ll oo = LLONG_MAX;
int n, m, cnt;
vt<vt<ii>> G; // G is a DAG
vt<bool> vs;
vt<int> topo;
vt<ll> d;

void dfs(int u){
    vs[u]=true;
    // cout << u << '\n';
    EACH(e, G[u]){
        int w(e.fi), v(e.se);
        if (!vs[v]){
            dfs(v);
        }
    }
    topo[--cnt]=u;
}

void topoSort(){
    topo = vt<int>(n, 0);
    cnt = n;
    vs = vt<bool>(n+1, false);
    FOR(i, 1, n+1){
        if (!vs[i]) dfs(i);
    } 
}

ll shortestPathDAG(vt<vt<ii>> G){
    vt<ll> d(n+1, oo);
    d[1] = 0LL;
    EACH(u, topo){
        EACH(e, G[u]){
            int w(e.fi), v(e.se);
            d[v] = min(d[v], d[u]+w);
        }
    }
    return d[n];
}

ll longestPathDAG(vt<vt<ii>> G){
    vt<vt<ii>> G_ = G;
    FOR(i, 1, n+1){
        EACH(e, G_[i])
            e.fi*=-1;
    }
    return -1*shortestPathDAG(G_);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    cin >> n >> m;
    G = vt<vt<ii>>(n+1);
    vs = vt<bool>(n+1, false);
    FOR(m){
        int u, v, w;
        cin >> u >> v >> w;
        G[u].pb(ii(w, v));
    }
    topoSort();
    cout << shortestPathDAG(G) << " " << longestPathDAG(G);
}