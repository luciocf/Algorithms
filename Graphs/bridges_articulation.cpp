// Finding Bridges and Articulation Points
// O(n+m)

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+10;

int in[maxn], low[maxn], tt;

bool art_point[maxn];

vector<int> grafo[maxn], bridge;

// One special case: When the root of the DFS tree has only one forward 
// edge, it is not an articulation point

void dfs(int u, int p)
{
	in[u] = low[u] = ++tt;

	for (auto v: grafo[u])
	{
		if (in[v] != 0)
		{
			if (v != p) low[u] = min(low[u], in[v]);
			continue;
		}

		dfs(v, u);

		if (low[v] > in[u]) bridge.push_back({u, v});
		if (low[v] >= in[u]) art_point[u] = true;

		low[u] = min(low[u], low[v]);
	}
}
