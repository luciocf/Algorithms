// Convex Hull Trick (not fully dynamic)
// Queries in O(log n)

#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef pair<int, int> pii;

vector<pii> env; // contains lines

// checks if line b is useless
bool bad(pii a, pii b, pii c)
{
	// for min queries, reverse this
    return (a.ss-c.ss)*(c.ff-b.ff) >= (b.ss-c.ss)*(c.ff-a.ff);
}

void add(pii line)
{
	while (env.size() > 1 && bad(env[env.size()-2], env.back(), line))
		env.pop_back();

	env.push_back(line);
}

int get(int mid, int x)
{
	return (env[mid].ff*x + env[mid].ss);
}

int query(int x)
{
	if (env.size() == 0) return get(0, x);

	int ini = 0, fim = env.size()-2, ans = get(env.size()-1, x);

	while (ini <= fim)
	{
		int mid = (ini+fim)>>1;

		if (get(mid, x) >= get(mid+1, x)) ans = get(mid, x), fim = mid-1;
		else ini = mid+1;
	}

	return ans;
}
