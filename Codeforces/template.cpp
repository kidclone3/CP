#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define vi vector<int>
#define ll long long
#define all(x) x.begin(), x.end()
#define F_OR(i, a, b, step) for (int i = (a); (step) > 0 ? i < (b) : i > (b); i += (step))
#define EACH(x, a) for (auto &x : a)
#define BUG(x)                    \
    {                             \
        cout << #x << " = " << x; \
    }
template <class T>
void print(T &x)
{
    for (auto &it : x)
    {
        cout << it << " ";
    }
    cout << "\n";
};

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // freopen("input.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    string a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    pair<int, int> x, y;
    map<pair<int, int>, vector<pair<int, int>>> mp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 'A')
                x = {i, j};
            if (a[i][j] == 'B')
                y = {i, j};

            if (a[i][j] != '#')
            {
                if ( i - 1 >= 0 && a[i - 1][j] != '#')
                    mp[{i, j}].push_back({i - 1, j});
                if (j - 1 >= 0 && a[i][j - 1] != '#' )
                    mp[{i, j}].push_back({i, j - 1});
                if (i + 1 < n && a[i + 1][j] != '#' )
                    mp[{i, j}].push_back({i + 1, j});
                if (j + 1 < m && a[i][j + 1] != '#')
                    mp[{i, j}].push_back({i, j + 1});
            }
        }
    }

    map<pair<int, int>, string> path;
    for (auto e : mp)
    {
        path[e.first] = "";
    }
    map<pair<int, int>, bool> visited;
    for (auto e : mp)
    {
        visited[e.first] = false;
    }

    visited[x] = true;
    queue<pair<int, int>> q;
    q.push(x);
    bool success = false;
    while (!q.empty())
    {
        pair<int, int> cha = q.front();
        q.pop();
        if(success) break;
        for (auto con : mp[cha])
        {
            if (visited[con])
                continue;
            visited[con] = true;

            if (con.first == cha.first)
            {
                if (con.second == cha.second + 1)
                    path[con] = path[cha] + "R";
                if (con.second == cha.second - 1)
                    path[con] = path[cha] + "L";
            }
            if (con.second == cha.second)
            {
                if (con.first == cha.first + 1)
                    path[con] = path[cha] + "D";
                if (con.first == cha.first - 1)
                    path[con] = path[cha] + "U";
            }
            if(con==y) {
                success = true;
                break;
            }

            q.push(con);
        }
    }

    if (path[y].size() == 0)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        cout << path[y].size() << endl;
        cout << path[y] << endl;
    }
}
