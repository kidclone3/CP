/*
Call diameter() -> return number of edge create diameter of tree
Just use dilemma: diameter = max(dfs(random_node), dfs(max_leaf))
*/


const int N = 3e5+5;
bitset<N> visited;
vector<int> adj[N];
int n;
int x; // use to track the farthest node

void dfs_utils(int u, int count, int &max_count) {
    visited[u] = true;
    count++;
    for(auto &v: adj[u]) {
        if (!visited[v]) {
            if (count > max_count) {
                x = v;
                max_count = count;
            }
            dfs_utils(v, count, max_count);
        }
    }
}

void dfs(int node, int &max_count) {
    int count = 0;
    visited.reset();
    dfs_utils(node, count, max_count); 
}

int diameter() {
    int max_count = INT_MIN;
    dfs(1, max_count);
    dfs(x, max_count);
    return max(0, max_count);
}