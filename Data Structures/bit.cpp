// Binary Indexed Tree (BIT)
// Update: O(log n)
// Query: O(log n)

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 10010;

int bit[MAXN], n;

void upd(int x, int v)
{
    for (; x <= n; x += (x&-x))
        bit[x] += v;
}

int query(int x)
{
    int ans = 0;
    for (; x > 0; x -= (x&-x))
        ans += bit[x];
    return ans;
}
