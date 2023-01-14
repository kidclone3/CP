#include<bits/stdc++.h>
using namespace std;

int n, m;
const int N = 1e4+5;
vector<vector<int>> edge(N);
bitset<N> visited;

vector<int> v_component, id_v_component;

vector<int> a;
void dfs(int u) {
    v_component.push_back(a[u]);
    id_v_component.push_back(u);
    visited[u] = true;
    for (auto &v: edge[u]) if (!visited[v]) dfs(v);
}
int solve() {
    cin >> n >> m;
    a.resize(n);
    for(auto &it: a) cin >> it;
    for(int i = 0 ; i < m; ++i) {
        int u, v; cin >> u >> v;
        v--; u--;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
   
    for(int i= 0; i < n; ++i) {
        if (!visited[i]) {
            dfs(i);
            sort(begin(v_component), end(v_component));
            sort(begin(id_v_component), end(id_v_component));

            // for (auto &it: v_component) cout << it << " "; cout << '\n';
            // for (auto &it: id_v_component) cout << it << " "; cout << '\n';
            for(int j = 0; j < id_v_component.size(); ++j) {
                a[id_v_component[j]] = v_component[j];
            }
            v_component.clear();
            id_v_component.clear();
        }
    }
    // for (auto &it: a) cout << it << " "; cout << '\n';
    // LCS:
    vector<int> lcs(n+5, 1e9);
    for(int i = 0; i < n; ++i) {
        auto it = lower_bound(begin(lcs), end(lcs), a[i]);
        *it = a[i];
    }
    for(int i = n; i >=0; --i) if (lcs[i] != 1e9) {
        cout << i+1;
        break;
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    solve();
}

