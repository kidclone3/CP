#include <bits/stdc++.h>
using namespace std;

int64_t solve(int64_t arr[], int u, int v);

int main(){
    int number, query;
    int u, v;
    register int i;

    cin >> number >> query;
    int64_t arr[number];
    for (i = 0; i < number; ++i){
        cin >> arr[i];
    }
    for (i = 0; i < query; ++i){
        cin >> u >> v;
        cout << solve(arr, u-1, v-1)<<'\n';
    }
    return 0;
}

int64_t solve(int64_t arr[], int u, int v){
    int64_t sum = 0, tempSum = 0, min, difference;
    int mid = (u+v)/2;
    int direction = 1;
    bool slope = true;
    register int i;

    for (i  = u; i <= v; ++i){
        sum += arr[i];
    }
    for (i = u; i <= mid; ++i){
        tempSum += i;
    }
    difference = sum - 2*tempSum;
    min = abs(difference);
    if (abs(difference-2*arr[mid+1]) > min){
        direction = -1;
    }
    i = mid;
    while (slope){
        i += direction;
        difference -= 2*direction*arr[i];
        if (abs(difference) < min){
            min = abs(difference);
        } else if (abs(difference) == min){
            continue;
        } else {
            slope = false;
        }
    }
    return min;
}
