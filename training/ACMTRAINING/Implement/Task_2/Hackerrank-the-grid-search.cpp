
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'gridSearch' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING_ARRAY G
 *  2. STRING_ARRAY P
 */
#define ll unsigned long long 
const ll MOD = (1ull<<61) - 1;
const ll MX = 3731;
const ll MY = 2999;
string gridSearch(vector<string> G, vector<string> P) {
    // first is hashing.
    int n = G.size();
    int m = G[0].size();
    vector<vector<ll>> a(n+1, vector<ll> (m+1, 0LL));
    vector<ll> px(n+1, 1LL), py(m+1, 1LL);
    for(int i = 0; i < n; ++i) px[i+1] = px[i]*MX;
    for(int i = 0; i < m; ++i) py[i+1] = py[i]*MY;

    for(int i = 0; i < n; ++i) 
        for(int j = 0; j < m; ++j) {
            a[i+1][j+1] = G[i][j] - '0' + 1;
        }
    for(int i = 0; i < n; ++i) 
        for(int j = 0; j < m; ++j) {
            // a[i][j+1] = (a[i][j]*MX % MOD + a[i][j+1]) % MOD;
            a[i][j+1] = a[i][j]*MX + a[i][j+1];
        }
    for(int i = 0; i < n; ++i) 
        for(int j = 0; j < m; ++j) {
            // a[i+1][j] = (a[i][j]*MY % MOD + a[i+1][j]) % MOD;
            a[i+1][j] = a[i][j]*MY + a[i+1][j];
        }
    auto hash = [&](int posx, int posy, int dx, int dy) {
        return (a[posx + dx][posy+dy] - a[posx+dx][posy]*py[dy]) - (a[posx][posy+dy] - a[posx][posy]*py[dy])*px[dx];
    };
    vector<vector<ll>> b(P.size()+1, vector<ll>(P[0].size()+1));
    for(int i = 0; i < (int)P.size(); ++i) 
        for(int j = 0; j < (int)P[0].size(); ++j) {
            b[i][j] = P[i][j]-'0'+1;
        }
    for(int i = 0; i < (int)P.size(); ++i) 
        for(int j = 0; j < (int)P[0].size(); ++j) {
            // a[i][j+1] = (a[i][j]*MX % MOD + a[i][j+1]) % MOD;
            b[i][j+1] = b[i][j]*MX + b[i][j+1];
        }
    for(int i = 0; i < (int)P.size(); ++i) 
        for(int j = 0; j < (int)P[0].size(); ++j) {
            // a[i+1][j] = (a[i][j]*MY % MOD + a[i+1][j]) % MOD;
            b[i+1][j] = b[i][j]*MY + b[i+1][j];
        }

    // Ok, finish the preCal.
    int nn = P.size(), mm = P[0].size();
    for(int i = 0; i < n-nn; ++i) 
        for(int j = 0; j < m-mm; ++j) {
            if (hash(i+1, j+1, nn, mm) == b[nn][mm]) {
                return "YES";
            }
        }

    // Debug:
    cerr << "Hash1: \n";
    for(int i = 0; i < (int)a.size(); ++i) 
        for(int j = 0; j < (int)a[0].size(); ++j) 
            cerr << a[i][j] << " \n"[j==a[0].size()-1];
    cerr <<'\n';
    cerr << "Hash2: \n";
    for(int i = 0; i < (int)b.size(); ++i) 
        for(int j = 0; j < (int)b[0].size(); ++j) 
            cerr << b[i][j] << " \n"[j==b[0].size()-1];
    cerr <<"\n";
    return "NO";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string t_temp;
    getline(cin, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));
    for (int t_itr = 0; t_itr < t; t_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int R = stoi(first_multiple_input[0]);

        int C = stoi(first_multiple_input[1]);

        vector<string> G(R);

        for (int i = 0; i < R; i++) {
            string G_item;
            getline(cin, G_item);

            G[i] = G_item;
        }

        string second_multiple_input_temp;
        getline(cin, second_multiple_input_temp);

        vector<string> second_multiple_input = split(rtrim(second_multiple_input_temp));

        int r = stoi(second_multiple_input[0]);

        int c = stoi(second_multiple_input[1]);

        vector<string> P(r);

        for (int i = 0; i < r; i++) {
            string P_item;
            getline(cin, P_item);

            P[i] = P_item;
        }

        string result = gridSearch(G, P);

        fout << result << "\n";
    }

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
