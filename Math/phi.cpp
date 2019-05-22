#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+10;

int phi[maxn];

void sieve(int n)
{
	for (int i = 1; i <= n; i++)
		phi[i] = i;

	for (int i = 2; i <= n; i++)
	{
		if (phi[i] == i)
		{
			phi[i] = i-1;

			for (int j = 2*i; j <= n; j+=i)
				phi[j] -= phi[j]/i;
		}
	}
}
