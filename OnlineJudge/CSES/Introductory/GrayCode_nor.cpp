#include<bits/stdc++.h>
using namespace std;

int n;
vector<string> ans;
unordered_map<string, bool> mp;
string x; // vector<char>

void gen() {
    if (ans.size() == (1<<n)) return;
    for(int i = n-1; i > -1; --i) {
        x[i] == '1' ? x[i] = '0' : x[i]= '1';
        if (!mp[x]) {
            mp[x] = true;
            ans.push_back(x);
            gen();
        }
        x[i] == '1' ? x[i] = '0' : x[i]= '1';
    }
}

int main() {
    cin >> n;
    x.resize(n, '0');
    mp[x] = true;
    ans.push_back(x);
    gen();
    for(auto it : ans) {
        cout << it << "\n";
    }
}