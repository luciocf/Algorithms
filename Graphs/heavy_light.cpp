// Heavy-Light Decomposition

#include <bits/stdc++.h>

using namespace std;

// Example: Greatest edge weight in a path (with edge update)

// Note: In this version, the heaviest edge of a vertex is always
// the first one. By doing that, we can use the same segment tree
// for both subtree and path queries

const int maxn = 1e5+10;

typedef pair<int, int> pii;

int pai[maxn], nivel[maxn], size[maxn], in[maxn], out[maxn], tt, n;

int head[maxn], num[maxn];

int tree[4*maxn];

vector<pii> grafo[maxn];

int dfs(int u, int p)
{
	size[u] = 1;

	if (grafo[u].size() > 1 && grafo[u][0].first == p) swap(grafo[u][0], grafo[u][1]);

	for (auto P: grafo[u])
	{
		int v = P.first;

		if (v == p) continue;

		pai[v] = u, nivel[v] = nivel[u]+1;
		num[v] = P.second;

		size[u] += dfs(v, u);

		if (size[v] > size[grafo[u][0].first]) swap(v, grafo[u][0].first);
	}

	return size[u];
}

void hld(int u, int p)
{
	in[u] = ++tt;

	for (auto P: grafo[u])
	{
		int v = P.first;
		if (v == p) continue;

		head[v] = (v == grafo[u][0].first ? head[u] : v);

		hld(v, u);
	}

	out[u] = tt;
}

int lca(int u, int v)
{
	while (head[u] != head[v])
	{
		if (nivel[head[u]] > nivel[head[v]]) u = pai[head[u]];
		else v = pai[head[v]];
	}
	
	if (nivel[u] > nivel[v]) return v;
	return u;
}

void build(int node, int l, int r)
{
	if (l == r)
	{
		tree[node] = num[l];
		return;
	}

	int mid = (l+r)>>1;

	build(2*node, l, mid); build(2*node+1, mid+1, r);

	tree[node] = max(tree[2*node], tree[2*node+1]);
}

void upd(int node, int l, int r, int pos, int v)
{
	if (l == r)
	{
		tree[node] = v, num[l] = v;
		return;
	}

	int mid = (l+r)>>1;

	if (pos <= mid) upd(2*node, l, mid, pos, v);
	else upd(2*node+1, mid+1, r, pos, v);

	tree[node] = max(tree[2*node], tree[2*node+1]);
}

int query(int node, int tl, int tr, int l, int r)
{
	if (tl > r || tr < l) return -1;
	if (tl >= l && tr <= r) return tree[node];

	int mid = (tl+tr)>>1;

	return max(query(2*node, tl, mid, l, r), query(2*node+1, mid+1, tr, l, r));
}

// the edge from u to its parent becomes v
void updNode(int u, int v)
{
	num[u] = v;
	upd(1, 1, n, in[u], v);
}

int queryPath(int u, int v)
{
	int ans = -1;
	while (true)
	{
		if (head[u] == head[v])
		{
			if (u == v) return ans;
			return max(ans, query(1, 1, n, in[head[u]]+1, in[u]));
		}

		ans = max(ans, query(1, 1, n, in[head[u]], in[u]));
		u = pai[head[u]];
	}
}

int main(){}
