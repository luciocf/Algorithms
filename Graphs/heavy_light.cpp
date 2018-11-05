// Heavy-Light Decomposition

 #include <bits/stdc++.h>

 using namespace std;

 const int maxn = 1e5+10;

 typedef pair<int, int> pii;

int pai[maxn], nivel[maxn], size[maxn], edge[maxn], n;

int chain[maxn], head[maxn], pos[maxn], qtd, c;

int tree[4*maxn];

vector<pii> grafo[maxn];

void DFS(int u, int p)
{
	size[u] = 1;
	
	for (auto P: grafo[u])
	{
		int v = P.first, d = P.second;
		if (v == p) continue;
		
 		DFS(v, u);
		
		pai[v] = u, nivel[v] = nivel[u]+1, edge[v] = d;
		size[u] += size[v];
	}
}

void hld(int u)
{
	if (!head[c]) head[c] = u;

 	chain[u] = c, pos[u] = ++qtd;

 	int maior = -1, ind = -1;
	for (auto P: grafo[u])
	{
		int v = P.first;
		if (v != pai[u] && size[v] > maior)
			maior = size[v], ind = v;
	}

 	if (ind != -1) hld(ind);

 	for (auto P: grafo[u])
	{
		int v = P.first;
		if (v != pai[u] && v != ind)
		{
			c++;
			hld(v);
		}
	}
}

int LCA(int u, int v)
{
	while (chain[u] != chain[v])
	{
		int c1 = chain[u], c2 = chain[v];
		if (nivel[head[c1]] > nivel[head[c2]]) u = pai[head[c1]];
		else v = pai[head[c2]];
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

void updNode(int u, int v)
{
	edge[u] = v;
	upd(1, 1, n, pos[u], v);
}

int queryPath(int u, int v)
{
	int ans = -1;
	
	while (true)
	{
		int c1 = chain[u], c2 = chain[v];
		if (c1 == c2)
		{
			if (u == v) return ans;
			return max(ans, query(1, 1, n, pos[v]+1, pos[u]));
		}
		
 		ans = max(ans, query(1, 1, n, pos[head[c1]], pos[u]));
		u = pai[head[c1]];
	}
}
