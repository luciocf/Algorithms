// Binary Exponentiation
// O(log n)

#include <bits/stdc++.h>

using namespace std;

int pot(int a, int b)
{
	if (!b) return 1;

	int t = pot(a, b/2);

	if (b&1) return a*t*t;
	return t*t;
}
