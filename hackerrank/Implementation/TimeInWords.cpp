#include <bits/stdc++.h>
using namespace std;

string intToString(int i) {
    string ans;
    string toWord[] = {"0", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", 
    "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty",
    "twenty one", "twenty two", "twenty three", "twenty four", "twenty five", "twenty six", "twenty seven", "twenty eight", "twenty nine"};
    return toWord[i];
}
string timeInWords(int h, int m) {
    string ans;
    
    if (m == 0) {
        ans = intToString(h) + " o' clock";
    }
    else if (m == 1) {
        ans = intToString(m) + " minute past " + intToString(h);
    }
    else if (m == 15) {
        ans = "quarter past " + intToString(h);
    }
    else if (m == 30) {
        ans = "half past " + intToString(h);
    }
    else if (1 <= m && m < 20) {
        ans = intToString(m) + " minutes past " + intToString(h);
    }
    else if (m == 20) {
        ans = intToString(m) + " minutes past " + intToString(h);
    }
    else if (20 < m && m < 30) {
        ans = intToString(m) + " minutes past " + intToString(h);
    }
    else if (m == 45) {
        ans = "quarter to " + (h + 1 == 13 ? intToString(1) : intToString(h + 1));
    }
    else {
        int mm = 60 - m;
        if (mm == 1) {
            ans = intToString(mm) + " minute to " + (h + 1 == 13 ? intToString(1) : intToString(h + 1));
        }
        else{
            ans = intToString(mm) + " minutes to " + (h + 1 == 13 ? intToString(1) : intToString(h + 1));
        }
    }
    return ans;
}

int main() {
    int h, m;
    cin >> h >> m;
    cout << timeInWords(h, m);
}