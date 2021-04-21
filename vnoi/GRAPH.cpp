#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()
#define FOR(i, a) for (int i = 0; i < (a); ++i) 
#define F0R(i, a, b) for (int i=(a); i < (b); ++i)
#define F_OR(i, a, b, step) for (int i=(a); (step)>0? i<(b) : i>(b); i+=(step))
#define EACH(x, a) for(auto& x: a)
template <class T>
#define IO                                  \
    {                                       \
        freopen("input.txt", "r", stdin);   \
        freopen("output.txt", "w", stdout); \
    }
void print(T &x)
{
    for (auto &it : x)
    {
        cout << it << " ";
    }
    cout << "\n";
};

void new_graph(vector<set<int>> &a, int n, int k) {
    if (k == 0) {
        return;
    }
    else {
        if (!a.empty()) a.clear();
        set<int> adj;
        FOR(j, n) {
                adj.insert(j);
            }
        FOR(i, n) {
            a.push_back(adj);
        }
    }
}
void add_graph(vector<set<int>> &a, int u, int v) {
    for (int i = 0; i < u; i++) {
        if (a.size() <= i)
            {
                set<int> tmp;
                a.push_back(tmp);
            }
    }
    a[u-1].insert(v-1);
}
void del_graph(vector<set<int>> &a, int u, int v) {
    if (!a.empty() && !a[u-1].empty())  {
        a[u-1].erase(v-1);
    }
}
pair<int, int> any_graph(vector<set<int>> &a) {
    FOR(i, a.size()) {
        if (!a[i].empty()) {
            int tmp = *a[i].begin();
            a[i].erase(a[i].begin());
            return {i+1, tmp+1};
        }
    }
    return {1, 1};
}
bool edg_graph(vector<set<int>> &a, int u, int v) {
    if (a.empty() || a[u-1].empty()) return false;
    return a[u-1].find(v-1) != a[u-1].end();
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // IO;
    string inp;
    getline(cin, inp);
    vector<set<int>> a;
    while (inp != "END")
    {
        string command;
        int u, v;
        stringstream ss(inp);
        ss >> command;
        if (command != "ANY")
            {
                ss >> u >> v;
                // cout << u << v;
            }
        if (command == "NEW") {
            new_graph(a, u, v);
        }
        if (command == "ADD") {
            add_graph(a, u, v);
        }
        if (command == "DEL" && !a.empty()) {
            del_graph(a, u, v);
        }
        if (command == "ANY" && !a.empty()) {
            int tmp1, tmp2;
            tie(tmp1, tmp2) = any_graph(a);
            cout << tmp1 << " " <<tmp2 << "\n";
        }
        if (command == "EDG" && !a.empty()) {
            edg_graph(a, u, v) ? (cout << "YES\n") : (cout << "NO\n");
        }
        getline(cin, inp);
    }
    
}