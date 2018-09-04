// Tarjan's Algorithm
// O(n+m)

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+10;
const int INF = 1e9+10;

int in[MAXN], low[MAXN], c, t;
vector<int> grafo[MAXN], comp[MAXN];
stack<int> stk;

void DFS(int u)
{
    in[u] = low[u] = ++t;
    stk.push(u);

    for (auto v: grafo[u])
    {
        if (in[v] != 0)
        {
            low[u] = min(low[u], in[v]);
            continue;
        }

        DFS(v);

        low[u] = min(low[u], low[v]);
    }

    if (low[u] == in[u])
    {
        c++;
        while (stk.top() != u)
        {
            comp[c].push_back(stk.top());

            in[stk.top()] = INF;
            stk.pop();
        }
        comp[c].push_back(stk.top());
        
        in[stk.top()] = INF;
        stk.pop();
    }
}
