// Tarjan's Algorithm for SCCs
// O(n+m)

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+10;

const int inf = 1e9+10;

int in[maxn], low[maxn], tt;
int scc[maxn], cc;

vector<int> grafo[maxn];

stack<int> stk;

void dfs(int u)
{
    in[u] = low[u] = ++tt;
    stk.push(u);

    for (auto v: grafo[u])
    {
        if (in[v])
        {
            low[u] = min(low[u], in[v]);
            continue; 
        }

        dfs(v);

        low[u] = min(low[u], low[v]);
    }

    if (low[u] != in[u]) return;

    ++cc;
    while (true)
    {
        int x = stk.top();
        stk.pop();

        scc[x] = cc, in[x] = inf;

        if (x == u) break;
    }
}
