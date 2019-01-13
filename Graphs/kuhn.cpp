// Kuhn's algorithm for Maximum Bipartite Matching
// O(nm)

#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e3+10;

int match[maxn];

bool mark[maxn];

vector<int> grafo[maxn];

bool dfs(int u)
{
    if (mark[u]) return false;

    mark[u] = true;
    for (auto v: grafo[u])
    {
        if (match[v] == -1 || dfs(match[v]))
        {
            match[v] = u;
            return true;
        }
    }

    return false;
}
    
// vertices in the left half are numbered 1 to n
int solve(int n)
{
    memset(match, -1, sizeof match);

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        memset(mark, 0, sizeof mark);

        if (dfs(i)) ans++;
    }

    return ans;
}
