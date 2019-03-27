// Treap
// O(log n) depth

#include <bits/stdc++.h>

using namespace std;

struct node
{
    int v, w, sz;
    node *l, *r;

    node()
    {
        v = 0, sz = 1, w = rand();
        l = r = NULL;
    }
};

typedef node*& node_t;

int sz(node *t){return (t ? t->sz : 0);}

void op(node *t)
{
    if (t) t->sz = sz(t->l)+sz(t->r)+1;
}

bool find(node *t, int x)
{
    if (!t) return false;

    if (t->v == x) return true;
    return find((x > t->v ? t->r : t->l), x);
}

void split(node *t, node_t l, node_t r, int v)
{
    if (!t) return void(l=r=NULL);

    if (t->v > v) split(t->l, l, t->l, v), r = t;
    else split(t->r, t->r, r, v), l = t;

    op(t);
}

void merge(node_t t, node *l, node *r)
{
    if (!l || !r) t = (l ? l : r);
    else if (l->w > r->w) merge(l->r, l->r, r), t = l;
    else merge(r->l, l, r->l), t = r;

    op(t);
}

void insert(node_t t, node *aux)
{
    if (!t) t = aux;
    else if (aux->w > t->w) split(t, aux->l, aux->r, aux->v), t = aux;
    else insert((aux->v > t->v ? t->r : t->l), aux);

    op(t);
}

void erase(node_t t, int v)
{
    if (t->v == v) merge(t, t->l, t->r);
    else erase((v > t->v ? t->r : t->l), v);

    op(t);
}
