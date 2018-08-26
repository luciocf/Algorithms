// Depth First Search (DFS)
// O(n+m)

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+10;

vector<int> grafo[MAXN];
bool mark[MAXN];

void DFS(int u)
{
	mark[u] = 1;
	for (auto v: grafo[u])
	{
		if (mark[v]) continue;

		DFS(v, u); // do stuff
	}
}
