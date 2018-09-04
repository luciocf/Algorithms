// Finding Bridges and Articulation Points
// O(n+m)

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+10;

int in[MAXN], low[MAXN], t;
bool art_point[MAXN];
vector<int> grafo[MAXN], bridge;

void DFS(int u, int p)
{
	in[u] = low[u] = ++t;

	for (auto v: grafo[u])
	{
		if (v == p) continue;

		if (in[v] != 0)
		{
			low[u] = min(low[u], in[v]);
			continue;
		}

		DFS(v, u);

		if (low[v] > in[u]) bridge.push_back({u, v});
		if (low[v] >= in[u]) art_point[u] = 1;

		low[u] = min(low[u], low[v]);
	}
}

// One special case: When the root of the DFS tree has only one forward 
// edge, it is not an articulation point
