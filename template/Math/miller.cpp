pair<ll, ll> factor(ll n)
{
	ll s = 0;
	while ((n & 1) == 0)
	{
		s++;
		n >>= 1;
	}
	return {s, n};
}
ll pow(ll a, ll d, ll n)
{
	ll r = 1;
	a = a % n;
	while (d > 0)
	{
		if (d & 1)
			r = (r * a) % n;
		d >>= 1;
		a = (a * a) % n;
	}
	return r;
}
bool test_a(ll s, ll d, ll n, ll a)
{
	if (n == a)
		return true;
	ll p = pow(a, d, n);
	if (p == 1)
		return true;
	for (; s > 0; s--)
	{
		if (p == n - 1)
			return true;
		p = p * p % n;
	}
	return false;
}
bool miller(ll n)
{
	if (n < 2)
		return false;
	if ((n & 1) == 0)
		return n == 2;
	ll s, d;
	tie(s, d) = factor(n - 1);

	if (n < 1373653)
	{
		return test_a(s, d, n, 2) && test_a(s, d, n, 3);
	}
	else if (n < 4759123141)
	{
		return test_a(s, d, n, 2) && test_a(s, d, n, 7) && test_a(s, d, n, 61);
	}
	else
	{
		return test_a(s, d, n, 2) && test_a(s, d, n, 3) && test_a(s, d, n, 5) && test_a(s, d, n, 7) && test_a(s, d, n, 11) && test_a(s, d, n, 13) && test_a(s, d, n, 17) && test_a(s, d, n, 19) && test_a(s, d, n, 23);
	}
}
