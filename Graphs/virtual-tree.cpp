// Virtual Tree Implementation
// Lúcio Cardoso

// Builds the Virtual Tree/Auxiliary Tree for a set of vertices in O(n log n)

#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef pair<int, int> pii;

const int maxn = 2e5+10;

int in[maxn], tt;

bool mark[maxn]; // marks important vertices

vector<int> grafo[maxn];

struct BinaryLifting
{
	int nivel[maxn], tab[maxn][20];

	void dfs(int u, int p)
	{
		in[u] = ++tt;

		for (auto v: grafo[u])
		{
			if (v == p) continue;

			nivel[v] = nivel[u]+1, tab[v][0] = u;

			dfs(v, u);
		}
	}

	void build(int n)
	{
		for (int j = 1; j < 20; j++)
			for (int i = 1; i <= n; i++)
				tab[i][j] = tab[tab[i][j-1]][j-1];
	}

	int lca(int u, int v)
	{
		if (nivel[u] < nivel[v]) swap(u, v);

		for (int i = 19; i >= 0; i--)
			if (nivel[u]-(1<<i) >= nivel[v])
				u = tab[u][i];

		if (u == v) return u;

		for (int i = 19; i >= 0; i--)
			if (tab[u][i] && tab[v][i] && tab[u][i] != tab[v][i])
				u = tab[u][i], v = tab[v][i];

		return tab[u][0];
	}

	int dist(int u, int v) {return nivel[u] + nivel[v] - 2*nivel[lca(u, v)];}
} LCA;

struct VirtualTree
{
	vector<pii> tree[maxn];

	void init(vector<int> &S)
	{
		for (auto v: S)
		{
			tree[v].clear();
			mark[v] = 0;
		}
	}

	void build(vector<int> &S)
	{
		auto comp = [&](int a, int b) {return in[a] < in[b];};

		sort(S.begin(), S.end(), comp);

		int m = S.size();

		for (int i = 1; i < m; i++)
			S.push_back(LCA.lca(S[i-1], S[i]));

		sort(S.begin(), S.end(), comp);
		S.erase(unique(S.begin(), S.end()), S.end());

		for (int i = 1; i < S.size(); i++)
		{
			int l = LCA.lca(S[i-1], S[i]);

			tree[S[i]].push_back({l, LCA.dist(l, S[i])});
			tree[l].push_back({S[i], LCA.dist(l, S[i])});
		}
	}
} T;
