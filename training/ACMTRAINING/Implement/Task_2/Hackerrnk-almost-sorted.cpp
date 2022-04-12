#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'almostSorted' function below.
 *
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

void almostSorted(vector<int> a) {
    int n = a.size();
    vector<int> b(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<int> suspect;
    suspect.clear();
    for(int i = 0; i < n; ++i) {
        if (a[i] != b[i]) suspect.push_back(i);
    }

    if (suspect.empty()) return void(cout << "yes");
    if (suspect.size() == 2) {
        cout << "yes\n"; 
        cout << "swap " << suspect[0]+1 << " " << suspect[1]+1;
        return;
    } else {

        reverse(a.begin() + suspect[0], a.begin() + suspect.back()+1);
        for(int i = 0; i < (int) suspect.size(); ++i) {
            if (a[suspect[i]] != b[suspect[i]]) return void(cout << "no");
        }
        cout << "yes\n";
        cout << "reverse " << suspect[0]+1 << " " << suspect.back()+1;
    }
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    almostSorted(arr);

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

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
