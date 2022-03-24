const int oo = 1e9;
vvii G;
vi d;

void dijkstra(){
    int n = G.size();
    priority_queue<ii, vii, greater<ii>> pq;
    pb.push(ii(0, 1));

    while(pq.size()){
        int u = pq.top().se,
            du = pq.top().fi;
        pq.pop();
        if (du!=d[u]) continue;

        FOR(i, G[u].size()){
            int v = G[u][i].se,
                uv = G[u][i].fi;
            if (d[v] > du+uv) d[v] = du+uv, pq.push({d[v], v});
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    int n, m;
    G = vvii(n+1);
    d = vi(n+1, oo);
    while(m--){
        int u, v, w;
        cin >> u >> v >> w;
        G[u].pb({w, v});
        G[v].pb({w, u});
    }
    dijkstra();
}