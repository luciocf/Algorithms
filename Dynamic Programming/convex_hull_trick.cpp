#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dd;

const dd inf = 1e9+10;

struct Line
{
	ll m, b;
	dd x;

	Line(ll m_=0, ll b_=0, dd x_=-inf) : m(m_), b(b_), x(x_){}

	bool operator <(const Line &o) const
	{
		return m > o.m;
	}

	bool operator <(const ll &o) const
	{
		return x < (dd)o;
	}
};

struct LineContainer : multiset<Line, less<>>
{
	bool hasPrev(iterator it) {return it != begin();}

	bool hasNext(iterator it) {return next(it) != end();}

	dd intersect(Line l1, Line l2)
	{
		return (dd)(l1.b-l2.b)/(l2.m-l1.m);
	}

	bool bad(Line l1, Line l2, Line l3)
	{
		return intersect(l1, l3) < intersect(l1, l2);
	}

	void get_x(iterator it)
	{
		if (hasPrev(it))
		{
			Line l = *it;

			l.x = intersect(*prev(it), *it);

			erase(it); insert(l);
		}
	}

	void add(ll m, ll b)
	{
		Line l(m, b);
		
		auto it = lower_bound(l);
		
		if (it != end() && it->m == m)
		{
		    if (it->b <= b) return;
		    erase(it);
		}
		
		it = insert(l);

		if (hasPrev(it) && hasNext(it) && bad(*prev(it), *it, *next(it)))
		{
			erase(it);
			return;
		}

		while (hasPrev(it) && hasPrev(prev(it)) && bad(*prev(prev(it)), *prev(it), *it))
			erase(prev(it));

		while (hasNext(it) && hasNext(next(it)) && bad(*it, *next(it), *next(next(it))))
			erase(next(it));

		get_x(it);
		if (hasNext(it)) get_x(next(it));
	}

	ll query(ll x)
	{
		auto it = lower_bound(x);
		
		if (it == end() || it->x > x) --it;

		return it->m*x + it->b;
	}
} env;
