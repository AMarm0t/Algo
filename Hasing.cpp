const int mod_1 = 1e9 + 7, mod_2 = 1e9 + 9;
const int N = 1e6 + 10;
const int base_1 = 137, base_2 = 139;

int pwr_1[N + 10], inv_1[N + 10], pwr_2[N + 10], inv_2[N + 10];

int big_mod(int base, int power, int mod)
{
	if (power == 0)
		return 1;
	if (power % 2)
	{
		int a = big_mod(base, power - 1, mod);
		return base * a  % mod;
	}
	int a = big_mod(base, power / 2, mod);
	{
		return a * a % mod;
	}
}

void pre()
{
	pwr_1[0] = pwr_2[0] = 1;

	for (int i = 1; i <= N; i++)
	{
		pwr_1[i] = (pwr_1[i - 1] * base_1 % mod_1) % mod_1;
		pwr_2[i] = (pwr_2[i - 1] * base_2 % mod_2) % mod_2;
	}
	inv_1[N] = big_mod(pwr_1[N], mod_1 - 2, mod_1);
	inv_2[N] = big_mod(pwr_2[N], mod_2 - 2, mod_2);

	for (int i = N - 1; i >= 0; i--)
	{
		inv_1[i] = (inv_1[i + 1] * base_1 % mod_1) % mod_1;
		inv_2[i] = (inv_2[i + 1] * base_2 % mod_2) % mod_2;
	}

}

vector<pair<int, int>> pre_hash(string &s)
{
	int n = s.size();

	vector<pair<int, int>>v(n);
	v[0] = {s[0], s[0]};

	for (int i = 1; i < n; i++)
	{
		v[i].first = (v[i - 1].first + s[i] * pwr_1[i] % mod_1) % mod_1;
		v[i].second = (v[i - 1].second + s[i] * pwr_2[i] % mod_2) % mod_2;
	}
	return v;

}

pair<int, int> subHash(string &s, int l, int r, vector<pair<int, int>>&preHash)
{
	if (l == 0)
		return preHash[r];
	int a = (preHash[r].first - preHash[l - 1].first + mod_1) % mod_1;
	a = (a * inv_1[l]) % mod_1;
	int b = (preHash[r].second - preHash[l - 1].second + mod_2) % mod_2;
	b = (b * inv_2[l]) % mod_2;
	return {a, b};
}
