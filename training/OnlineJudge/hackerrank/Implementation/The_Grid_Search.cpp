#include<bits/stdc++.h>
using namespace std;

string gridSearch(vector<string> G, vector<string> P) {
    // bruteforce?
    int n = G.size();
    int m = G[0].size();
    int n_P = P.size();
    int m_P = P[0].size();
    for (int i = 0; i < n - n_P; i++)
    {
        for (int j = 0; j < m - m_P; j++)
        {
            if (G[i].substr(j, m_P) == P[0]) {
                bool yes = true;
                for (int z = 1; z < n_P; ++z) {
                    if (G[i + z].substr(j, m_P) != P[z]) {
                        yes = false;
                        break;
                    }
                }
                if (yes) {
                    return "YES";  
                }
            }     
        } 
    }
    return "NO";
    
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        int n, m;
        cin >> n >> m;
        vector<string> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        cin >> n >> m;
        vector<string> b(n);
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
        }
        cout << gridSearch(a, b) << "\n";
        
    }
}