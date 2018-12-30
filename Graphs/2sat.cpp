// 2-SAT (Boolean Satisfiability)
// O(n+m)

#include <bits/stdc++.h>

using namespace std;

const int maxn = 5e5+10;

typedef pair<int, int> pii;

int num[maxn], comp[maxn];

bool assign[maxn];

bool mark[maxn];

vector<int> grafo[maxn], g2[maxn];

stack<int> stk;

void dfs(int u)
{
	mark[u] = 1;
	for (auto v: grafo[u])
		if (!mark[v])
			dfs(v);
	stk.push(u);
}

// get components in topological order
void dfs2(int u, int c)
{
	mark[u] = 1, comp[u] = c;
	for (auto v: g2[u])
		if (!mark[v])
			dfs2(v, c);
}

bool solve(int n)
{
	for (int i = 0; i < n; i++)
		if (!mark[i])
			dfs(i);

	memset(mark, 0, sizeof mark);

	int cc = 0;	
	while (!stk.empty())
	{
		int u = stk.top(); stk.pop();
		if (mark[u]) continue;

		dfs2(u, ++cc);
	}

	// indices 2*k and 2*k+1 represent the kth variable if
	// assigned true or false, respectively
	for (int i = 0; i < n; i += 2)
	{
		if (comp[i] == comp[i+1]) return false;
		assign[i/2] = (comp[i] > comp[i+1]);
	}

	return true;
}
