const int d4x[] = {-1, 0, 1, 0},
          d4y[] = {0, -1, 0, 1},
          d8x[] = {-1, -1, -1, 0, 0, 1, 1, 1},
          d8y[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int n, m, cnt;
vt<int> res;
vt<vt<int>> G;
vt<bool> vs;

void dfs(int u){
    EACH(v, G[u]){
        if (!vs[v]){
            vs[v] = true;
            dfs(v);
        }
    }
    res[--cnt]=u;
}

void topoSort(){
    res = vt<int>(n);
    cnt=n;
    vs = vt<bool>(n+1, false);
    FOR(i, 1, n+1){
        if (!vs[i]){
            vs[i]=true;
            dfs(i);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    freopen("test.inp", "r", stdin);
    freopen("test.out", "w", stdout);

    cin >> n >> m;
    G = vt<vt<int>>(n+1);
    FOR(m){
        int u, v;
        cin >> u >> v;
        G[u].pb(v);
    }
    topoSort();
    EACH(u, res) cout << u << '\n';
    
}