#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'candies' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY arr
 */

long candies(int n, vector<int> arr) {
    // Code rieng th toan bo ptu giong nhau.
    vector<int> a(n+4, 0);
    a[0] = INT_MIN;
    a[n+1] = INT_MAX;
    for(int i = 1; i <= n; ++i) {
        a[i] = arr[i-1];
    }
    vector<int> res(n+4, 0);
    // Suspect just for some node cannot place right now.
    stack<int> suspect;
    for(int i = 1; i <= n; ++i) {
        // Tinh tien
        if (a[i-1] < a[i] && a[i] <= a[i+1])
            res[i] = res[i-1] + 1;
        else if (a[i-1] >= a[i] && a[i] <= a[i+1]) {
            res[i] = 1;
        } else {
            suspect.push(i);
        }
    }
    while (!suspect.empty()) {
        int i = suspect.top();
        suspect.pop();
        if (a[i-1] < a[i] && a[i] > a[i+1]) {
            res[i] = max(res[i-1], res[i+1]) + 1;
        } else res[i] = res[i+1]+1;
    }
    int ans = 0;
    for(int i = 1; i <= n; ++i) {
        ans += res[i];
    }
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        string arr_item_temp;
        getline(cin, arr_item_temp);

        int arr_item = stoi(ltrim(rtrim(arr_item_temp)));

        arr[i] = arr_item;
    }

    long result = candies(n, arr);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
