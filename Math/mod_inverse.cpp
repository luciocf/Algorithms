// Modular Inverse with Extended Euclidean Algorithm
// O(log n)

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

// we want to find x such that ax == 1 (mod m)
// so solve the linear equation ax+my = 1

pii get(int a, int b)
{
	if (a == 0) return {0, 1};

	pii P = get(b%a, a);

	int x1 = P.first, y1 = P.second;

	return {y1-(b/a)*x1, x1};
}
