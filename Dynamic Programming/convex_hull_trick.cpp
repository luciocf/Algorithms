// Convex Hull Trick
// O(log n) per query and insertion

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

typedef double dd;

struct Line
{
	// 0 for a line
	// 1 for an x-coord query
	bool type;

	// leftmost x-coordinate covered by line
	dd left;

	// slope and y-intercept
	ll m, b;
};

bool operator < (const Line &a, const Line &b)
{
	if (a.type || b.type) return a.left < b.left;

	return a.m > b.m; // for max queries reverse this
}

typedef set<Line>::iterator sli;

set<Line> env;

bool first(sli it)
{
	return it == env.begin();
}

bool last(sli it)
{
	return next(it) == env.end();
}

bool bad(Line l1, Line l2, Line l3)
{
    return (l3.b-l1.b)*(l1.m-l2.m) < (l2.b-l1.b)*(l1.m-l3.m);
}

dd intersect(Line l1, Line l2)
{
	return (dd)(l2.b-l1.b)/(l1.m-l2.m);
}

void get_left(sli it)
{
	if (!first(it))
	{
		Line l = *it;

		l.left = intersect(*prev(it), *it);

		env.erase(it);
		env.insert(l);
	}
}


void add(Line l)
{
	sli it = env.lower_bound(l);

	// parallel case
	if (it != env.end() && it->m == l.m)
	{
		if (it->b <= l.b) return;
		env.erase(it);
	}

	env.insert(l);
	it = env.find(l);

	// check if the inserted line is useless
	if (!first(it) && !last(it) && bad(*prev(it), *it, *next(it)))
	{
		env.erase(it);
		return;
	}

	// remove lines on the right
	while (!last(it) && !last(next(it)) && bad(*it, *next(it), *next(next(it))))
		env.erase(next(it));

	// remove lines on the left
	while (!first(it) && !first(prev(it)) && bad(*prev(prev(it)), *prev(it), *it))
		env.erase(prev(it));

	// update left values
	get_left(it);
	if (!last(it)) get_left(next(it));
}

ll query(ll x)
{
	sli it = env.upper_bound({1, (dd)x, 0, 0});
	it--;

	return it->m * x + it->b;
}
