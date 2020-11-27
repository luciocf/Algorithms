// Matriz Exponentiation
// O(n^3 log n)

#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9+7;

struct Matriz
{
	int n, m;
	vector< vector<int> > d; 

	Matriz(int n, int m) : n(n), m(m)
	{
		d.assign(n, vector<int>(m));
	}

	Matriz operator*(const Matriz &o)
	{
		Matriz ans(n, o.m);

		for (int i = 0; i < n; i++)
			for (int j = 0; j < o.m; j++)
				for (int k = 0; k < m; k++)
					ans.d[i][j] = (ans.d[i][j] + (1ll*d[i][k]*o.d[k][j])%mod)%mod;

		return ans;
	}

	static Matriz pot(Matriz a, long long b)
	{
		Matriz ans(a.n, a.m);

		for (int i = 0; i < a.n; i++)
			ans.d[i][i] = 1; 

		for (; b; b /= 2, a = a * a)
			if (b%2)
				ans = ans * a;

		return ans;
	}
};
