#include <bits/stdc++.h>
using namespace std;

string x;
string s = "abacaba";
void solve();
bool check(string s1);
bool generate_answer(int i);

int main() {
    int t;
    cin >> t;
    while(t--) solve();
}

bool check(string s1) {
    for(int i = 0; i < 7; ++i) {
        if (s1[i] != s[i] && s1[i] != '?') return false;
    }
    return true;
}

bool generate_answer(int i){
    string x1 = x.substr(0, i);
    string x3 = x.substr(i+7, (int) x.length() - (i + 7));
    for(int j = 0; j < (int) x1.length(); ++j) {
        if (x1[j] == '?') x1[j] = 'd';
    }
    for(int j = 0; j < (int) x3.length(); ++j) {
        if (x3[j] == '?') x3[j] = 'd';
    }

    string tmp = x1 + s + x3;
    int cnt = 0;

    for(int j = 0; j < (int) tmp.size() - 6; ++j) {
        string tmp2 = tmp.substr(j, 7);
        if (check(tmp2)) cnt++;
    }
    if (cnt == 1) {
        cout << "Yes\n";
        cout << tmp << "\n";
        return true;
    }
    return false;
}

void solve() {
    int n;
    cin >> n;
    cin >> x;
    vector<int> ucv;
    for(int i = 0; i < n - 6; ++i) {
        string s1 = x.substr(i, 7);
        if (check(s1)) {
            ucv.push_back(i);
        }
    }
    for(int i : ucv) {
        if (generate_answer(i)) {
            return;
        }
    }
    cout << "No\n";
}
