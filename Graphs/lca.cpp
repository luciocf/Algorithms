// Lowest Common Ancestor (LCA)
// O(log n)

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+10;
const int MAXL = 20;

int pai[MAXN], nivel[MAXN], tab[MAXN][MAXL];
vector<int> grafo[MAXN];

void DFS(int u, int p)
{
    for (auto v: grafo[u])
    {
    	if (v == p) continue;

        nivel[v] = nivel[u]+1, pai[v] = u;
        DFS(v, u);
    }
}

void build(void)
{
    memset(tab, -1, sizeof tab);

    for (int i = 1; i <= n; i++)
        tab[i][0] = pai[i];

    for (int j = 1; j < MAXL; j++)
        for (int i = 1; i <= n; i++)
            if (tab[i][j-1] != -1)
                tab[i][j] = tab[tab[i][j-1]][j-1];
}

int LCA(int u, int v)
{
    if (nivel[u] < nivel[v]) swap(u, v);

    for (int i = MAXL-1; i >= 0; i--)
        if (nivel[u] - (1<<i) >= nivel[v])
            u = tab[u][i];

    if (u == v) return u;

    for (int i = MAXL-1; i >= 0; i--)
        if (tab[u][i] != -1 && tab[v][i] != -1 && tab[u][i] != tab[v][i])
            u = tab[u][i], v = tab[v][i];
        
    return pai[u];
}
