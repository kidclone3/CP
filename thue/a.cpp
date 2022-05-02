#include <iostream>
#include <vector>
#include <set>

int main()
{
    int n, m;
    std::cin >> n >> m;
    std::vector<int> adj[n + 1];
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        std::cin >> u >> v;
        adj[u].push_back(i);
    }
    std::set<int> table1, table2;
    int check[n + 1];
    std::fill(check, check + n + 1, 0);
    for (int i = 1; i <= n; ++i)
    {
        if (check[i] == 0)
        {
            if (table1.find(i) == table1.end() && table2.find(i) == table2.end())
            {
                table1.insert(i);
                check[i] = 1;
                for (auto it : adj[i])
                {
                    table2.insert(it);
                    check[it] = 2;
                }
            }
        }
        else
        {
            for (auto it : adj[i])
            {
                if (check[it] == 0)
                {
                    if (check[i] == 1)
                    {
                        table2.insert(it);
                        check[it] = 2;
                    }
                    else
                    {
                        table1.insert(it);
                        check[it] = 1;
                    }
                }
                else
                {
                    if (check[it] == check[i])
                    {
                        std::cout << "NO";
                        return 0;
                    }
                }
            }
        }
    }
    for (int i = 1; i <= n; ++i)
        std::cerr << check[i] << " ";

    std::cout << "YES\n";
    for (auto it : table1)
        std::cout << it << " ";
}
