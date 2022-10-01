#include <bits/stdc++.h>
using namespace std;

vector<int> solve(int N, vector<int> c, vector<int> p, vector<int> w) {
  // Write your code here
}

int main() {

  ios::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  vector<int> c(N);
  for (int i_c = 0; i_c < N; i_c++) {
    cin >> c[i_c];
  }
  vector<int> p(N - 1);
  for (int i_p = 0; i_p < N - 1; i_p++) {
    cin >> p[i_p];
  }
  vector<int> w(N - 1);
  for (int i_w = 0; i_w < N - 1; i_w++) {
    cin >> w[i_w];
  }

  vector<int> out_;
  out_ = solve(N, c, p, w);
  cout << out_[0];
  for (int i_out_ = 1; i_out_ < out_.size(); i_out_++) {
    cout << " " << out_[i_out_];
  }
}
