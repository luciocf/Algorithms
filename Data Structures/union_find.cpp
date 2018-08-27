// Union-Find
// O(alpha(n))

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+10;

int pai[MAXN], size[MAXN];

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
