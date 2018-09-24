// Centroid Decomposition

// Problem: Given a tree, find all pairs of vertices (x, y) such
// that their distance is exactly k

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+10;

int qtd[maxn], size[maxn], n, k, ans;

bool mark[maxn];

vector<int> grafo[maxn];


// Reset subtree size
int dfs(int u, int p)
{
	size[u] = 1;

	for (auto v: grafo[u])
	{
		if (v == p || mark[v]) continue;

		size[u] += dfs(v, u);
	}

	return size[u];
}

// Find Centroid
int centroid(int u, int p, int S)
{
	for (auto v: grafo[u])
	{
		if (v == p || mark[v]) continue;

		if (size[v] > S/2) return centroid(v, u, S);
	}

	return u;
}

// Update distances from centroid subtree
void upd(int u, int p, int d, int val)
{
	qtd[d] += val;

	for (auto v: grafo[u])
	{
		if (v == p || mark[v]) continue;

		upd(v, u, d+1, val);
	}
}

// Find all pairs on distinct subtrees with distance k
int get(int u, int p, int d)
{
	if (d == k) return 2*qtd[0];

	int aux = qtd[k-d];

	for (auto v: grafo[u])
	{
		if (v == p || mark[v]) continue;

		aux += get(v, u, d+1);
	}

	return aux;
}

// Decompose Tree
void decompose(int u)
{
	dfs(u, 0);

	int c = centroid(u, 0, size[u]);
	mark[c] = 1;

	upd(c, 0, 0, 1);

	int aux = 0;
	for (auto v: grafo[c])
	{
		if (mark[v]) continue;

		upd(v, c, 1, -1);
		aux += get(v, c, 1);
		upd(v, c, 1, 1);
	}

	ans += aux/2;

	upd(c, 0, 0, -1);

	for (auto v: grafo[c])
		if (!mark[v]) decompose(v);
}
