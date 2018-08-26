// Breadth First Search (BFS)
// O(n+m)

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+10;

vector<int> grafo[MAXN];
bool mark[MAXN];

void BFS(int u)
{
	queue<int> fila;
	fila.push(u);
	mark[u] = 1;

	while (!fila.empty())
	{
		int x = fila.front();
		fila.pop();

		for (auto v: grafo[x])
		{
			if (mark[v]) continue;
			mark[v] = 1, fila.push(v); // do stuff
		}
	}
}
