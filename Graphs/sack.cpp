// Sack (DSU on Tree)
// O(n log n)

#include <bits/stdc++.h>

using namespace std;

// Given a tree where each vertex has a certain color, find
// the frequency of a certain color in each subtree

const int maxn = 2e5+10;

int num[maxn], qtd[maxn];

int sz[maxn], st[maxn], en[maxn], pos[maxn], tt;

vector<int> grafo[maxn], s[maxn];

int find_size(int u, int p)
{
	sz[u] = 1;
	st[u] = ++tt, pos[tt] = num[u];

	for (auto v: grafo[u])
	{
		if (v == p) continue;

		sz[u] += find_size(v, u);
	}

	en[u] = tt;

	return sz[u];
}

void dfs(int u, int p, bool heavy)
{
	int maior = -1, ind = -1;

	// find heavy child
	for (auto v: grafo[u])
		if (v != p && sz[v] > maior)
			maior = sz[v], ind = v;

	// solve for light children, then remove them
	for (auto v: grafo[u])
		if (v != p && v != ind)
			dfs(v, u, 0);

	// solve for heavy child, without removing it
	if (ind != -1)
		dfs(ind, u, 1);

	qtd[num[u]]++;

	// add children back
	for (auto v: grafo[u])
	{
		if (v == p || v == ind) continue;

		// v's subtree
		for (int i = st[v]; i <= en[v]; i++)
		{
			int x = pos[i];

			s[u].push_back(x);
			qtd[num[x]]++;
		}
	}

	// if u is not a heavy child, remove it
	if (!heavy)
	{
		for (int i = st[u]; i <= en[u]; i++)
		{
			int x = pos[i];
			qtd[num[x]]--;
		}
	}
}
