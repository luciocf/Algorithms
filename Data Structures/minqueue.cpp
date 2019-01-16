// Minqueue
// O(1) amortized

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

struct MinQueue
{
	deque<pii> dq;
	int l, r;

	void init(void)
	{
		l = r = 0;
		dq.clear();
	}

	void push(int x)
	{
		while (!dq.empty() && x < dq.back().ff) dq.pop_back();
		dq.push({x, r});
		r++;
	}

	void pop(void)
	{
		if (!dq.empty() && dq.front().ss == l) dq.pop_front();
		l++;
	}

	int getmin(void) {return dq.front().ff;}
};
