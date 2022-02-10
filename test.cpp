#include <bits/stdc++.h>
using namespace std;
 
#define endl '\n'
#define vi vector<long long int>
#define ll long long int
#define all(x) x.begin(), x.end()
 
const ll MOD = 1000000000000000009;
const ll mod = 1000000007;
 
 
template <template <typename, typename> class C, typename K, typename V> 
std::ostream &operator<<(std::ostream &os, C<K, V> a)
{
	os << "[ ";
	for (auto t : a)
	{
		os << t << " ";
	}
	os << "]";
	return os;
}
template <template <typename> class V, typename T> 
std::ostream &operator<<(std::ostream &os, V<T> a)
{
	os << "[ ";
	for (T t : a)
	{
		os << t << " ";
	}
	os << "]";
	return os;
}
template <typename T, typename V> 
std::ostream &operator<<(std::ostream &os, pair<T, V> a)
{
	os << "[" << a.first << ", " << a.second << "]";
	return os;
}
 
template <typename T>
std::istream &operator>>(std::istream &is, vector<T> &a)
{
	for (T &t : a)
	{
		is >> t;
	}
	return is;
}
template <typename T, typename V>
std::istream &operator>>(std::istream &is, pair<T, V> &a)
{
	is >> a.first >> a.second;
	return is;
}
 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
 
	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);
	int t = 1;
	// cin >> t;
	while (t--)
	{
		vi a(5);
		map<int, int> b;
		for (int i = 0; i < 5; i++)
		{
			a[i] = i * 2;
			b[i] = i * 2;
		}
		cout << a << endl;
		cout << b << endl;
	}
}
