// 2D Binary Indexed Tree
// Update: O(log n log m)
// Query: O(log n log m)

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10010;

int bit[MAXN][MAXN], n, m;

void upd(int x, int y, int v)
{
    for (int i = x; i <= n; i += (i&-i))
        for (int j = y; j <= m; j += (j&-j))
            bit[i][j] += v;
}

int query(int x, int y)
{
    int ans = 0;
    for (int i = x; i > 0; i -= (i&-i))
        for (int j = y; j > 0; j -= (j&-j))
            ans += bit[i][j];
    return ans;
}
