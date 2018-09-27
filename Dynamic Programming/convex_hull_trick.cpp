// Convex Hull Trick

#include <bits/stdc++.h>
#define ff first
#define ss second

using namespace std;

typedef pair<int, int> pii;

vector<pii> v; // contains lines

// true if b is never minimal, false otherwise
bool bad(pii a, pii b, pii c)
{
    return (a.ss-c.ss)*(c.ff-b.ff) >= (b.ss-c.ss)*(c.ff-a.ff);
}

// add new line
void add(pii line)
{
	while (v.size() > 1 && bad(v[v.size()-2], v[v.size()-1], line))
		v.pop_back();
	v.push_back(line);
}

int get(int mid, int x)
{
	return (v[mid].ff*x+v[mid].ss);
}

// find value of minimal line
int busca(int x)
{
	if (v.size() == 0) return get(0, x);

	int ini = 0, fim = v.size()-2, ans = get(v.size()-1, x);

	while (ini <= fim)
	{
		int mid = (ini+fim)/2;

		if (get(mid, x) <= get(mid+1, x)) ans = get(mid, x), fim = mid-1;
		else ini = mid+1;
	}

	return ans;
}
