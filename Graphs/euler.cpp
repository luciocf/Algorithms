// Finding an Eulerian Circuit
// O(n+m)

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+10;

typedef pair<int, int> pii;

bool mark[maxn];

// stores (u, edge)
vector<pii> grafo[maxn];

vector<int> path;

void dfs(int u)
{
	for (auto v: grafo[u])
	{
		if (!mark[v.second])
		{	
			mark[v.second] = 1;
			dfs(v.first);
		}
	}

	path.push_back(u);
}
