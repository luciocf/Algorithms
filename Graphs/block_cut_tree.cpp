// Finds biconnected components and builds Block-Cut Tree
// Complexity: O(n+m)

#include <bits/stdc++.h>

#define all(x) x.begin(), x.end()
#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 2e5+10;

int n;

pii edge[maxn];

int in[maxn], low[maxn], tt;
bool mark_edge[maxn], art[maxn];

int sz_bcc[maxn];

vector<vector<int>> bcc;
vector<int> tree[maxn];

vector<pii> grafo[maxn];

stack<int> stk;

void make_component(int last)
{
	bcc.push_back(vector<int>());

	while (!stk.empty())
	{
		int e = stk.top(); stk.pop();

		bcc.back().push_back(e);

		if (e == last) break;
	}
}

void lowlink(int u, bool isroot)
{
	in[u] = low[u] = ++tt;

	bool fwd = 0;

	for (auto pp: grafo[u])
	{
		int v = pp.ff, e = pp.ss;
		if (mark_edge[e]) continue;

		mark_edge[e] = 1;
		stk.push(e);

		if (in[v])
		{
			low[u] = min(low[u], in[v]);
			continue;
		}

		lowlink(v, 0);

		low[u] = min(low[u], low[v]);

		if (isroot ? fwd : (low[v] >= in[u]))
		{
			art[u] = 1;
			make_component(e);
		}

		fwd = 1;
	}
}

void build(void)
{
	for (int i = 1; i <= n; i++)
	{
		if (in[i]) continue;

		int l = bcc.size();

		lowlink(i, 1);
		make_component(0);

		int r = bcc.size();

		for (int j = l; j < r; j++)
		{
			vector<int> v;

			for (auto e: bcc[j])
			{
				v.push_back(edge[e].ff);
				v.push_back(edge[e].ss);
			}

			sort(all(v));
			v.erase(unique(all(v)), v.end());

			for (auto u: v)
			{
				if (art[u])
				{
					tree[n+j+1].push_back(u);
					tree[u].push_back(n+j+1);
				}
				else
				{
					sz_bcc[n+j+1]++;
				}
			}
		}
	}
}
