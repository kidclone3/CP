#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

struct DSU {
    vector<int> lab;

    DSU(int n) : lab(n+1, -1) {}

    int getRoot(int u) {
        if (lab[u] < 0) return u;
        return lab[u] = getRoot(lab[u]);
    }

    bool merge(int u, int v) {
        u = getRoot(u); v = getRoot(v);
        if (u == v) return false;
        if (lab[u] > lab[v]) swap(u, v);
        lab[u] += lab[v];
        lab[v] = u;
        return true;
    }

    bool same_component(int u, int v) {
        return getRoot(u) == getRoot(v);
    }

    int component_size(int u) {
        return -lab[getRoot(u)];
    }
};
// }}}
using ll = long long;
struct Edge {
    int u, v;
    ll c;
};
bool operator < (const Edge& a, const Edge& b) {
    return a.c < b.c;
}
ostream& operator << (ostream& out, const Edge& e) {
    out << e.u << " - " << e.v << " [" << e.c << ']';
    return out;
}
std::pair<ll, std::vector<Edge>> mst(
        int n,
        std::vector<Edge> edges) {
    std::sort(edges.begin(), edges.end());

    DSU dsu(n + 1);  // tolerate 1-based index
    ll total = 0;
    vector<Edge> tree;
    for (const auto& e : edges) {
        const auto [u, v, c] = e;
        if (dsu.merge(u, v)) {
            total += c;
            tree.push_back(e);
        }
    }
    return {total, tree};
}
int main() {
    int V, E; cin >> V >> E;
    unordered_map<string, int> nameMap;
    vector<string> people(V);
    for(int i = 0; i < V; ++i) {
        cin >> people[i];
        nameMap[people[i]] = i;
    }
    vector<Edge> adj;
    for(int i = 0; i < E; ++i) {
        string person1, person2;
        int weight;
        cin >> person1 >> person2 >> weight;
        adj.push_back({nameMap[person1], nameMap[person2], weight});
        adj.push_back({nameMap[person2], nameMap[person1], weight});
    }
    auto result = mst(V, adj);
//    cout << result.second;
    int sum = 0;
    for(auto &it: result.second) {
        cout << people[it.u] << " " << people[it.v] <<'\n';
        sum += it.c;
    }
    cout << sum << '\n';
}