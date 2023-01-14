ll reflective(ll l, ll r, ll s)
{
	long double i = 1;
	long long int ans = 0;
	long double LL = INT64_MIN;
	long double rr = INT64_MAX;
	while (r > i)
	{
		i *= s;
		LL = ceil(l / i);
		rr = floor(r / i);
		ans += rr - LL + 1;
	}
	return ans;
}