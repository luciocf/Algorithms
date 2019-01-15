// Bounded Knapsack
// O(n*m)

#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

const int maxn = 1e2+10;
const int maxm = 1e5+10;
const int inf = 1e9+10;

typedef pair<int, int> pii;

struct MinQueue
{
	int l, r, sum;
	deque<pii> dq;

	void init(void)
	{
		l = r = sum = 0;
		dq.clear();
	}

	void push(int v)
	{
		while (!dq.empty() && v < dq.back().ff+sum) dq.pop_back();
		dq.push_back({v-sum, r});
		r++;
	}

	void pop(void)
	{
		if (!dq.empty() && dq.front().ss == l) dq.pop_front();
		l++;
	}

	void add(int v) {sum += v;}

	int getmin(void) {return dq.front().ff;}

	int size(void) {return r-l;}
};

int w[maxn], c[maxn], b[maxn];
int dp[maxm];

MinQueue q[maxm];

void solve(int n, int m)
{
	for (int i = 1; i <= m; i++) dp[i] = inf;

	for (int i = 1; i <= n; i++)
	{
		for (int i = 0; i < w[i]; i++) q[i].init();

		for (int j = 0; j <= m; j++)
		{
			int k = j%w[i];

			if (q[k].size() > b[i]) q[k].pop();

			q[k].add(c[i]);
			q[k].push(dp[j]);

			dp[j] = q[k].getmin();
		}
	}
}

int main(void)
{
	
}