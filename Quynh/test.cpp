#include <bits/stdc++.h>

using namespace std;
// int a;


int main() {
    
	int a[] = {2, 3, 1, 5 , 4};
    vector<int> b = {2, 3, 1, 5, 4};
    sort(a, a+3);
    sort(b.begin(), b.begin() + 3);
    cout << "a:\n";
    for (int i = 0; i < 5; i++) {
        cout << a[i] << " " ;
    }
    cout << "\nb:\n";
    for (int it : b) {
        cout << it << " ";
    }
    // for (auto it : b) {
    //     cout << it << " ";
    // }
	return 0;
}
// tóm lại là: Muốn thay đổi 1 giá trị = 1 hàm, thì khi khai báo giá trị đấy trong hàm, thêm dấu & phía trước.