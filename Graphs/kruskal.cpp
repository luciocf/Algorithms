// Kruskal
// O(m log m)

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+10;
const int MAXM = 1e5+10;

struct Edge {
    int x, y, d;
} aresta[MAXM];

int pai[MAXN], size[MAXN], n, m;

int Find(int x)
{
    if (pai[x] == x) return x;
    return pai[x] = Find(pai[x]);
}

void Join(int x, int y)
{
    x = Find(x), y = Find(y);
    if (x == y) return;

    if (size[x] < size[y]) swap(x, y);

    size[x] += size[y], pai[y] = x;
}

bool comp(Edge a, Edge b)
{
    return a.d < b.d;
}

int main(void)
{
	// Read Edges

	sort(aresta, aresta+m, comp);

    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        if (Find(aresta[i].x) != Find(aresta[i].y))
        {
            Join(aresta[i].x, aresta[i].y);
            ans += aresta[i].d;
        }
    }
}
