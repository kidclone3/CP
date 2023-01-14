

const int d4x[] = {-1, 0, 1, 0},
          d4y[] = {0, -1, 0, 1},
          d8x[] = {-1, -1, -1, 0, 0, 1, 1, 1},
          d8y[] = {-1, 0, 1, -1, 1, -1, 0, 1},
          N = 2e3+1,
          oo = 1e9;
int n, // number of vertices 
    m, // number of edges
    s, // start vertex
    e; // end vertex
ll d[N][N]; // distance from x to y

void floydWarshall(){
    FOR(i, 1, n+1){
        FOR(j, 1, n+1){
            FOR(k, 1, n+1){
                d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    // freopen("test.inp", "r", stdin);
    // freopen("test.out", "w", stdout);

    cin >> n >> m;
    FOR(i, 1, n+1){
        FOR(j, 1, n+1) d[i][j] = oo;
    }
    FOR(i, 1, n+1) d[i][i]=0;
    FOR(m){
        int u, v, w;
        cin >> u >> v >> w;
        d[u][v] = w;
    }
    cin >> s >> e;
    floydWarshall();
    cout << d[s][e];
}