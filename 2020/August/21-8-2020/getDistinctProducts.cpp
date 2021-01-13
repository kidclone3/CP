#include <bits/stdc++.h>
using namespace std;
vector<string> getDistinctProducts(vector<string> products){
	set<string> distinctProducts;
    distinctProducts.insert(products.begin(), products.end());
    vector<string> res;
    res.insert(res.begin(), distinctProducts.begin(), distinctProducts.end());
    return res;
}

int main()
{

}