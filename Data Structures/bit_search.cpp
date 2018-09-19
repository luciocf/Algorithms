// Search in BIT
// O(log n)

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+10;

int bit[MAXN], lg[MAXN], n;

// Find position of first prefix sum with value v
int busca(int v)
{
	int pos = 0, soma = 0;

	for (int i = 1<<lg[n]; i+pos <= n; i>>1)
		if (soma+bit[pos+i] < v)
			soma += bit[pos+i], pos += i;

	return pos+1;
}
