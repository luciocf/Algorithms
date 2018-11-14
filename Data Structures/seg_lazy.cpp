// Segment Tree with Lazy Propagation
// Update: O(log n)
// Query: O(log n)

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5+10;

int tree[4*MAXN], lazy[4*MAXN], num[MAXN];

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

void flush(int node, int l, int r)
{
    if (!lazy[node]) return;

    if (l != r)
    {
        lazy[2*node] += lazy[node];
        lazy[2*node+1] += lazy[node];
    }

    tree[node] += (r-l+1)*lazy[node];

    lazy[node] = 0;
}

void upd(int node, int tl, int tr, int l, int r, int v)
{
    flush(node, tl, tr);
    if (tl > r || tr < l) return;

    if (tl >= l && tr <= r)
    {
        lazy[node] += v;
        flush(node, tl, tr);
        return;
    }

    int mid = (tl+tr)>>1;

    upd(2*node, tl, mid, l, r, v);
    upd(2*node+1, mid+1, tr, l, r, v);

    tree[node] = tree[2*node]+tree[2*node+1];
}

int query(int node, int tl, int tr, int l, int r)
{
    flush(node, tl, tr);
    if (tl > r || tr < l) return 0;

    if (tl >= l && tr <= r) return tree[node];

    int mid = (tl+tr)>>1;

    int p1 = query(2*node, tl, mid, l, r);
    int p2 = query(2*node+1, mid+1, tr, l, r);

    return (p1+p2);
}
