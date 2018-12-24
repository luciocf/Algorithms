#include <bits/stdc++.h>

using namespace std;

const int maxn = 1e5+10;

const int inf = 1e9+10;

int in[maxn], low[maxn], cc, tt;

int comp[maxn];

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

    if (low[u] == in[u])
    {
        ++cc;
        while (stk.top() != u)
        {
            comp[stk.top()] = cc;
            in[stk.top()] = inf;

            stk.pop();
        }

        comp[u] = cc;
        in[u] = inf;

        stk.top();
    }
}
