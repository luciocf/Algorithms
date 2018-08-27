// Kosaraju's Algorithm
// O(n+m)

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+10;

vector<int> grafo[2][MAXN];
stack<int> pilha;
bool mark[MAXN];

void DFS(int u, int k)
{
	mark[u] = 1;
	for (auto v: grafo[k][u])
	{
		if (mark[v]) continue;

		DFS(v, k);
	}
	if (k == 0) pilha.push(u);
}

int main(void)
{
	for (int i = 1; i <= n; i++)
		if (!mark[i])
			DFS(i, 0);
	
	memset(mark, 0, sizeof mark);
	int ans = 0;

	while (!pilha.empty())
	{
		int x = pilha.top();
		pilha.pop();

		if (mark[x]) continue;

		DFS(x, 1);
		ans++;
	}
}
