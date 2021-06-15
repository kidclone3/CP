#include <bits/stdc++.h> 
using namespace std;

string encryption(string s) {
    
    int l = s.size();
    int col = ceil(sqrt(l));
    vector<string> encrypt;
    
    for (int i = 0; i < l; i+=col) {
        string tmp = s.substr(i, min(col, l - i));
        // cout << tmp << "\n";
        encrypt.push_back(tmp);    
    }
    string res = "";
    for (int i = 0; i < l; ++i) {
        string tmp = "";
        for (int j = 0; j < (int) encrypt.size(); ++j) {
            if (i >= (int) encrypt[j].size()) break;
            tmp += encrypt[j][i];
        }
        res += tmp;
        if (i + 1 < l)
            res += " ";
    }
    return res;
}

int main() {
    string s;
    cin >> s;
    cout << encryption(s);
}