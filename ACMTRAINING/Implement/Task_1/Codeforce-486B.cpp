#include<bits/stdc++.h>
using namespace std;
int main() {
   int n, m; cin >> n >> m;
   int b[n][m];
   vector<vector<int>> a(n, vector<int>(m, 1));
   
   vector<vector<int>> bb(n, vector<int>(m, 0));
   for (int i = 0; i < n; ++i)
       for(int j = 0; j < m; ++j) {
           cin >> b[i][j];
           if (b[i][j] == 0) {
               for(int x = 0; x < n; ++x) {
                   a[x][j] = 0;
               }
               for(int y = 0; y < m; ++y) {
                   a[i][y] = 0;
               }
           }
       }
   bool isOk = true;
    for(int i = 0; i < n; ++ i) {
        for(int j = 0; j < m; ++ j) {
            int tmp = 0;
            for(int x = 0; x < n; ++x) if(x != i) tmp |= a[x][j];
            for(int y = 0; y < m; ++y) if(y != j) tmp |= a[i][y];
            tmp |= a[i][j];
            if (tmp != b[i][j]) {
                isOk = false;
                break;
            }
        }
    }
    if (isOk) {
        cout << "YES\n";
        for(int i = 0; i < n; ++ i) 
            for(int j = 0; j < m; ++j) {
                cout << a[i][j] << " \n"[j==m-1];
            }
    } else cout << "NO";
}
