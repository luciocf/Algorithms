// Segment Tree
// Update: O(log n)
// Query: O(log n)

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+10;

int tree[4*MAXN], num[MAXN];

void build(int node, int l, int r)
{
    if (l == r)
    {
        tree[node] = num[l];
        return;
    }

    int mid = (l+r)>>1;

    build(2*node, l, mid); build(2*node+1, mid+1, r);

    tree[node] = tree[2*node]+tree[2*node+1];
}

void upd(int node, int l, int r, int pos, int v)
{
    if (l == r)
    {
        tree[node] = v;
        return;
    }

    int mid = (l+r)>>1;

    if (pos <= mid) upd(2*node, l, mid, pos, v);
    else upd(2*node+1, mid+1, r, pos, v);

    tree[node] = tree[2*node]+tree[2*node+1];
}

int query(int node, int tl, int tr, int l, int r)
{
    if (tl > r || tr < l) return 0;
    if (tl >= l && tr <= r) return tree[node];

    int mid = (tl+tr)>>1;

    int p1 = query(2*node, tl, mid, l, r);
    int p2 = query(2*node+1, mid+1, tr, l, r);

    return (p1+p2);
}
