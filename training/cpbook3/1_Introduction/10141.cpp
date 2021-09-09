#include<bits/stdc++.h>
using namespace std;
int n, p;
int main() {
    int c = 1;
    while(true) {
        cin >> n >> p;
        cin.ignore(1000, '\n');
        if (n == p && n == 0) break;
        if(c > 1) cout << '\n';
        int c1 = -1;
        double price1; string name1;
        // unordered_set<string> st;
        for (int i = 0; i < n; i++)
        {
            string s; getline(cin, s);
            // st.insert(s);
        }
        for(int i = 0; i < p; ++i) {
            string name; getline(cin, name);
            double price;
            int m;
            cin >> price >> m;
            cin.ignore(1000, '\n');
            int count = 0;
            for (int j = 0; j < m; j++)
            {
                string tmp;
                getline(cin, tmp);
                // if (st.count(tmp)) count++;
            }
            if (c1 < m){
                c1 = m;
                name1 = name;
                price1 = price;
            }
            else if (c1 == m && price < price1) {
                    price1 = price;
                    name1 = name;
            }
        }
        cout << "RFP #" << c++ << "\n";
        cout << name1 << "\n";
    }
}