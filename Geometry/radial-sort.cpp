// Comparison function to sort points radially w.r.t the origin

#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef pair<int, int> pt;

bool comp(pt a, pt b)
{
	if (a.y >= 0 && b.y < 0) return 1;
	if (a.y < 0 && b.y >= 0) return 0;

	if (a.y == 0 && b.y == 0)
	{
		if (a.x >= 0 && b.x < 0) return 1;
		if (a.x < 0 && b.x >= 0) return 0;

		return mod(a) < mod(b);
	}

	if (cross(a, b) == 0) return mod(a) < mod(b);

	return cross(a, b) > 0;
}
