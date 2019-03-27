// Implicit Treap
// O(log n) depth

#include <bits/stdc++.h>

using namespace std;

struct node
{
	node *l, *r;
	int v, w, sz, sum, lazy;

	node(int vv)
	{
		v = sum = vv, lazy = 0, sz = 1, w = rand();
		l = r = NULL;
	}
};

typedef node*& node_t;

int sz(node *t){return (t ? t->sz : 0);}

int sum(node *t){return (t ? t->sum : 0);}

void op(node *t)
{
	if (t)
	{
		t->sz = sz(t->l)+sz(t->r)+1;
		t->sum = sum(t->l)+sum(t->r)+t->v;
	}
}

void flush(node *t)
{
	if (!t) return;

	if (t->l) t->l->lazy += t->lazy;
	if (t->r) t->r->lazy += t->lazy;

	t->v += t->lazy, t->sum += t->lazy;
	t->lazy = 0;
}

void split(node *t, node_t l, node_t r, int pos, int add=0)
{
    if (!t) return void(l=r=NULL);

    flush(t);

    int v = add+sz(t->l);

    if (v >= pos) split(t->l, l, t->l, pos, add), r = t;
    else split(t->r, t->r, r, pos, v+1), l = t;

    op(t);
}

void merge(node_t t, node *l, node *r)
{
	flush(l); flush(r);

	if (!l || !r) t = (l ? l : r);
	else if (l->w > r->w) merge(l->r, l->r, r), t = l;
	else merge(r->l, l, r->l), t = r;

	op(t);
}

void insert(node_t t, int pos, int v)
{
    node *t1 = NULL, *t2 = NULL;
    node *aux = new node(v);

    flush(t);

    split(t, t1, t2, pos);
    merge(t1, t1, aux);
    merge(t, t1, t2);

    op(t);
}

void erase(node_t t, int pos, int add=0)
{
	flush(t);

    int v = add+sz(t->l);

    if (v == pos) merge(t, t->l, t->r);
    else if (v > pos) erase(t->l, pos, add);
    else erase(t->r, pos, v+1);

    op(t);
}

int upd(node_t t, int l, int r, int v)
{
	node *t1 = NULL, *t2 = NULL, *t3 = NULL;

	split(t, t1, t2, l);
	split(t2, t2, t3, r-l+1);

	t2->lazy += v;

	merge(t2, t2, t3);
	merge(t, t1, t2);
}

int query(node *t, int l, int r)
{
    node *t1, *t2, *t3;
    t1 = t2 = t3 = NULL;

    split(t, t1, t2, l);
    split(t2, t2, t3, r-l+1);

    int ans = t2->sum;

    merge(t2, t2, t3);
    merge(t, t1, t2);

    return ans;
}
