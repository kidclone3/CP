template <typename _Tp>
vector<_Tp> get_divisor(_Tp n)
{
	vector<_Tp> arr;
	factorize(n, arr);
	map<_Tp, int> prime;
	for (_Tp i : arr)
		prime[i]++;
	vector<_Tp> res(1, 1);
	for (auto it : prime)
	{
		int k = res.size();
		_Tp val = 1;
		for (int i = 0; i < it.second; ++i)
		{
			val *= it.first;
			for (int j = 0; j < k; ++j)
			{
				res.push_back(res[j] * val);
			}
		}
	}
	return res;
}