// Convex Hull Trick
// O(log n) per query and insertion

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef double dd;

struct Line
{
	// 0 for lines in the envelope
	// 1 for x-coord queries
	char type;

	// leftmost x-coord covered by line
	dd x;

	// slope and y-intercept
	ll m, b;
};

typedef set<Line>::iterator sit;

set<Line> env;

bool operator< (const Line &a, const Line &b)
{
	if (a.type+b.type > 0) return a.x < b.x;

	return a.m < b.m; // reverse this for max queries
}

bool hasPrev(sit it)
{
	return (it != env.begin());
}

bool hasNext(sit it)
{
	return (next(it) != env.end());
}

dd intersect(Line l1, Line l2)
{
	return (dd)(l2.b-l1.b)/(l1.m-l2.m);
}

bool bad(Line l1, Line l2, Line l3)
{
	return intersect(l1, l3) < intersect(l1, l2);
}

void get_x(sit it)
{
	if (hasPrev(it))
	{
		Line l = *it;

		l.x = intersect(*prev(it), *it);

		env.erase(it); env.insert(l);
	}
}

void add(ll m, ll b)
{
	Line l = {0, 0, m, b};

	sit it = env.lower_bound(l);

	// parallel lines case
	if (it != env.end() && it->m == l.m)
	{
		if (it->b <= l.b) return;
		env.erase(it);
	}

	env.insert(l);
	it = env.find(l);

	// checks if line is useless
	if (hasPrev(it) && hasNext(it) && bad(*prev(it), *it, *next(it)))
	{
		env.erase(it);
		return;
	}

	// remove lines in the right
	while (hasNext(it) && hasNext(next(it)) && bad(*it, *next(it), *next(next(it))))
		env.erase(next(it));

	// remove lines in the left
	while (hasPrev(it) && hasPrev(prev(it)) && bad(*prev(prev(it)), *prev(it), *it))
		env.erase(prev(it));

	// update the leftmost x-coord value
	get_x(it);
	if (hasNext(it)) get_x(next(it));
}

ll query(ll x)
{
	sit it = env.upper_bound({1, (dd)x, 0, 0});
	it--;

	return (it->m * x + it->b);
}
