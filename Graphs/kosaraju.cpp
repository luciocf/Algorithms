// Kosaraju's Algorithm
// O(n+m)

#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+10;

int scc[maxn];

bool mark[maxn];

// normal and transposed graphs
vector<int> grafo[2][maxn];

stack<int> stk;

void dfs1(int u)
{
    mark[u] = 1;

    for (auto v: grafo[0][u])
        if (!mark[v])
            dfs1(v);

    stk.push(u);
}

void dfs2(int u, int cc)
{
    scc[u] = cc;

    for (auto v: grafo[1][u])
        if (!scc[v])
            dfs2(v, cc);
}

void kosaraju(int n)
{
    for (int i = 1; i <= n; i++)
        if (!mark[i])
            dfs1(i);

    int cc = 0;
    while (!stk.empty())
    {
        int u = stk.top();
        stk.pop();

        if (!scc[u]) dfs2(u, ++cc);
    }
}
