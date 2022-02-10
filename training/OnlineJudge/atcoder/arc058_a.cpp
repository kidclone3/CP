#include <bits/stdc++.h>
using namespace std;
vector<int> d;
bool solve(int n){
    string s = to_string(n);
    for (auto& it1 : s) {
        for(auto& it2:d) {
            if (it1-'0' == it2) return false;
        }
    }
    return true;
}

int main() {
    int n, k;
    cin >> n >> k;
    for (int  i = 0; i < k; i++)
    {
        int tmp; 
        cin >> tmp;
        d.push_back(tmp);
    }
    while(true) {
        if (solve(n)) {
            cout << n <<'\n';
            return 0;
        }
        n++;
    }

    
}