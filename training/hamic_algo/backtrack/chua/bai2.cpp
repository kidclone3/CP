#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a;
vector<string> ans;
vector<int> nhom;
int tong = 0;
bool found = false;

void out() {
    vector<int> dem (k);
    vector<vector<int>> tmp(k);
    for(int i = 0; i < n; ++i) {
        cout << nhom[i] << " ";
        dem[nhom[i]] += a[i];
        tmp[nhom[i]].push_back(a[i]);
    }
    cout << '\n';
    for (int i = 0; i < k; ++i) {
        if (dem[i] != tong/k) return;
    }
    string result = "";
    for (int i = 0; i < k; ++i) {
        string tmp1 = "";
        for (auto& it : tmp[i]) {
            tmp1 += to_string(it) + " ";
        }
        result = result + tmp1 + "\n";
    }
    found = true;
    ans.push_back(result);
}

void dequy(int i) {
    if (found) return;
    if (i == n) {
        out();
        return;
    }
    for (int j = 0; j < k; ++j) {
        nhom.push_back(j);
        dequy(i+1);
        nhom.pop_back();
    }
}

int main() {
    cin >> n >> k;
    a.resize(n);
    for (int  i = 0; i < n; i++)
    {
        cin >> a[i];
        tong += a[i];
    }
    if (tong % k) {
        cout << "-1";
        return 0;
    }
    dequy(0);
    for (auto& it1 : ans) {
        cout << "------------\n";
        cout << it1 << "\n";
    }
}