#include <bits/stdc++.h>
using namespace std;

long candies(int n, vector<int> arr) {
    if (n == 1) return 1;
    vector<int> dp(n, 0);
    stack<int> st;
    if (arr[0] <= arr[1]) {
        dp[0] = 1;
    }
    else {
        st.push(0);
    }
    int i = 1;
    for (; i < n-1; i++)
    {
        if (arr[i] < arr[i+1] && arr[i] < arr[i-1]) {
            dp[i] = 1;
            while(!st.empty()) {
                dp[st.top()] = dp[st.top() + 1] + 1;
                st.pop();
            }
            i++;
            break;
        }
        else {
            st.push(i);
        }

    }
    if (!st.empty()) {
        dp[n-1] = 1;
        while(!st.empty()) {
            dp[st.top()] = dp[st.top() + 1] + 1;
            st.pop();
        }
    }
    else {
        dp[n-1] = dp[n-2] + 1;
    }
    long ans = 0;
    for (int i = 0 ; i < n; ++i) {
        ans += dp[i];
        cout << dp[i] << " ";
    }    
    cout << "\n";
    return ans;
    
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << candies(n, a); 
}