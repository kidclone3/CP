#include <bits/stdc++.h>
using namespace std;

string biggerIsGreater (string w) {
    for (int i = (int) w.size() - 1; i > 0; --i) {
        if (w[i] > w[i-1]) {
            swap(w[i], w[i-1]);
            return w;
        }
    }
    return "no answer";
}

int main() {
    int t;
    cin >> t;
    while(t--) {
        string s;
        cin >> s;
        cout << biggerIsGreater(s) <<'\n';
    }
}