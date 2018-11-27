// Block Cut Tree

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+10;

int in[maxn], low[maxn], id[maxn], tt, cc;

bool art[maxn];

vector<int> grafo[maxn], tree[maxn], stk;

vector< vector<int> > comp;

void dfs(int u, int p)
{
	in[u] = low[u] = ++tt;
	stk.push_back(u);

	for (auto v: grafo[u])
	{
		if (v == p) continue;

		if (in[v]) low[u] = min(low[u], in[v]);
		else
		{
			dfs(v, u);
			low[u] = min(low[u], low[v]);

			if (low[v] >= in[u])
			{
				art[u] = (in[u] > 1 || in[v] > 2);

				comp.push_back({u});
				while (stk.back() != u)
					comp.back().push_back(stk.back()), stk.pop_back();
			}
		}
	}
}

void get_tree(int n)
{
	for (int i = 1; i <= n; i++)
		if (art[i]) id[i] = ++cc;

	for (auto &C: comp)
	{	
		cc++;
		for (auto u: C)
		{
			if (!art[u]) id[u] = cc;
			else tree[id[u]].push_back(cc), tree[cc].push_back(id[u]);
		}
	}
}
