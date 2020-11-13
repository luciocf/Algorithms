// Comparison function to sort points radially w.r.t the origin

#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int, int> pt;

ll mod(pt a)
{
	return 1ll*a.x*a.x + 1ll*a.y*a.y;
}

ll cross(pt a, pt b)
{
	return 1ll*a.x*b.y - 1ll*a.y*b.x;
}

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
