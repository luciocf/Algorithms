// Euler Tour
// O(n + m)

#include <bits/stdc++.h>

using namespace std;

#define ff first
#define ss second

const int maxn =  1e5+10;

typedef pair<int, int> pii;

// (vértice, ind da aresta)
vector<pii> grafo[maxn];
 
int ind[maxn];
bool mark[maxn];
vector<int> ciclo;
 
void dfs(int u, int x)
{
	while (ind[u] < grafo[u].size())
	{
		int v = grafo[u][ind[u]].ff, e = grafo[u][ind[u]].ss;
		++ind[u];
 
		if (!mark[e])
		{
			mark[e] = 1;
			dfs(v);
		}
	}
 
	ciclo.push_back(u);
}
