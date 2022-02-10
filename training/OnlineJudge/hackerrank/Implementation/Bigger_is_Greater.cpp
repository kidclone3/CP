#include <bits/stdc++.h>
using namespace std;

string biggerIsGreater (string w) {
    int n = w.size();
    int i;
    for(i = n - 2; i >= 0; --i) {
        if (w[i] < w[i+1]) break;
    }
    if (i == -1) return "no answer";
    else {
        for (int j = n-1; j > i; --j) {
            if (w[i] < w[j]) {
                swap(w[i], w[j]);
                break;
            }
        }
        sort(w.begin() + i + 1, w.end());
        return w;
    }
}


int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        cout << biggerIsGreater(s) << "\n";
    }
}