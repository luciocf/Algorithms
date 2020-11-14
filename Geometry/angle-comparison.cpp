// Comparison function checking if the angle between a pair of vectors (a1, b1) is smaller than the one between (a2, b2).

#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int, int> pt;

ll cross(pp a, pp b)
{
	return 1ll*a.x*b.y - a.y*b.x;
}

ll dot(pp a, pp b)
{
	return 1ll*a.x*b.x + a.y*b.y;
}

bool comp(pt a1, pt b1, pt a2, pt b2)
{
	pt p1 = {dot(a1, b1), abs(cross(a1, b1))};
	pt p2 = {dot(a2, b2), abs(cross(a2, b2))};

	return cross(p1, p2) > 0;
}
