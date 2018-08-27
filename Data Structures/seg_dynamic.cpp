// Dynamic Segment Tree
// Update: O(log n)
// Query: O(log n)

#include <bits/stdc++.h>

using namespace std;

struct Node {
    int v;
    Node *l, *r;

    Node() {
        v = 0;
        l = r = NULL;
    }
};

int get(Node *node)
{
    if (!node) return 0;
    return node->v;
}

void upd(Node *node, int l, int r, int pos, int v)
{
    if (l == r)
    {
        node->v = v;
        return;
    }

    int mid = (l+r)>>1;

    if (pos <= mid)
    {
        if (node->l == NULL) node->l = new Node;
        upd(node->l, l, mid, pos, v);
    }
    else
    {
        if (node->r == NULL) node->r = new Node;
        upd(node->r, mid+1, r, pos, v);
    }

    node->v = get(node->l)+get(node->r);
}

int query(Node *node, int tl, int tr, int l, int r)
{
    if (!node || tl > r || tr < l) return;
    if (tl >= l && tr <= r) return node->v;

    int mid = (tl+tr)>>1;

    int p1 = query(node->l, tl, mid, l, r);
    int p2 = query(node->r, mid+1, tr, l, r);

    return (p1+p2);
}
