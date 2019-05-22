// Convex Hull
// O(n log n)

#include <bits/stdc++.h>

#define x first
#define y second

using namespace std;

const int maxn = 1e5+10;

typedef pair<int, int> pt;

int n;

pt a[maxn];

vector<pt> env;

int cross(pt a, pt b)
{
	return a.x*b.y - a.y*b.x;
}

bool cw(pt a, pt b, pt c)
{
	b.x -= a.x, b.y -= a.y;
	c.x -= a.x, c.y -= a.y;

	return cross(b, c) < 0;
}

bool ccw(pt a, pt b, pt c)
{
	b.x -= a.x, b.y -= a.y;
	c.x -= a.x, c.y -= a.y;

	return cross(b, c) > 0;
}

void convex_hull(void)
{
	sort(a+1, a+n+1);

	vector<pt> lower, upper;

	pt p1 = a[1], p2 = a[n];

	lower.push_back(p1), upper.push_back(p1);

	for (int i = 2; i <= n; i++)
	{
		if (i == n || cw(p1, a[i], p2))
		{
			while (upper.size() >= 2 && !cw(upper[upper.size()-2], upper.back(), a[i]))
				upper.pop_back();

			upper.push_back(a[i]);
		}

		if (i == n || ccw(p1, a[i], p2))
		{
			while (lower.size() >= 2 && !ccw(lower[lower.size()-2], lower.back(), a[i]))
				lower.pop_back();

			lower.push_back(a[i]);
		}
	}

	for (int i = 0; i < upper.size(); i++)
		env.push_back(upper[i]);
	for (int i = lower.size()-2; i >= 1; i--)
		env.push_back(lower[i]);
}
