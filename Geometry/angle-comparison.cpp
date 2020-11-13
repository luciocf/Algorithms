// Comparison function checking if the oriented angle between a pair of vectors (a1, b1) is smaller
// than the one between (a2, b2).

// For non-oriented angles, use the absolute value of the cross product

#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

typedef long long ll;
typedef pair<int, int> pt;

ll cross(pp a, pp b)
{
	return a.x*b.y - a.y*b.x;
}

ll dot(pp a, pp b)
{
	return a.x*b.x + a.y*b.y;
}

bool comp(pp a1, pp b1, pp a2, pp b2)
{
	pp p1 = {dot(a1, b1), cross(a1, b1)};
	pp p2 = {dot(a2, b2), cross(a2, b2)};

	return cross(p1, p2) > 0;
}
