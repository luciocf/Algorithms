// 2D Binary Indexed Tree
// Update: O(log n log m)
// Query: O(log n log m)

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10010;

int bit[MAXN][MAXN], n, m;

void upd(int x, int y, int v)
{
    for (; x <= n; x += (x&-x))
        for (; y <= m; y += (y&-y))
            bit[x][y] += v;
}

int query(int x, int y)
{
    int ans = 0;
    for (; x <= n; x -= (x&-x))
        for (; y <= m; y -= (y&-y))
            ans += bit[x][y];
    return ans;
}
