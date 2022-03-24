template <typename _Tp>
int rabin(_Tp n)
{
	if (n == 2)
		return 1;
	if (n < 2 || !(n & 1))
		return 0;
	const _Tp p[9] = {2, 3, 5, 7, 11, 13, 17, 19, 23};
	_Tp a, d = n - 1, mx = 4;
	int i, r, s = 0;
	while (!(d & 1))
	{
		++s;
		d >>= 1;
	}
	for (i = 0; i < mx; i++)
	{
		if (n == p[i])
			return 1;
		if (!(n % p[i]))
			return 0;
		a = powmod(p[i], d, n);
		if (a != 1)
		{
			for (r = 0; r < s && a != n - 1; r++)
				a = mulmod(a, a, n);
			if (r == s)
				return 0;
		}
	}
	return 1;
}