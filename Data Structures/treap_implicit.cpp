// Implicit Treap

#include <bits/stdc++.h>

using namespace std;

struct node
{
	node *l, *r;
	int v, w, sz, soma, lazy;

	node()
	{
		l = r = NULL;
		v = soma = lazy = 0, sz = 1, w = rand();
	}
};

typedef node*& node_t;

int sz(node *t)
{
	if (!t) return 0;
	return t->sz;
}

int soma(node *t)
{
	if (!t) return 0;
	return t->soma;
}

void op(node *t)
{
	if (t)
	{
		t->sz = 1+sz(t->l)+sz(t->r);
		t->soma = t->v+soma(t->l)+soma(t->r);
	}
}

void flush(node *t)
{
	if (!t) return;

	if (t->l) t->l->lazy += t->lazy;
	if (t->r) t->r->lazy += t->lazy;

	t->v += t->lazy, t->soma += t->lazy;
	t->lazy = 0;
}

void split(node *t, int x, node_t l, node_t r, int add=0)
{
	if (!t) return void(l=r=NULL);

	flush(t);

	int pos = add+sz(t->l);
	if (pos >= x) split(t->l, x, l, t->l, add), r = t;
	else split(t->r, x, t->r, r, pos+1), l = t;

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

void insert(node_t t, int pos, int x)
{
	node *aux = new node(), *l = NULL, *r = NULL;
	aux->v = aux->soma = x;

	flush(t);

	split(t, pos, l, r);
	merge(l, l, aux);
	merge(t, l, r);

	op(t);
}

void erase(node_t t, int pos, int add=0)
{
	flush(t);

	if (pos == add+sz(t->l)) merge(t, t->l, t->r);
	else if (pos < add+sz(t->l)) erase(t->l, pos, add);
	else erase(t->r, pos, add+sz(t->l)+1);

	op(t);
}

int upd(node_t t, int l, int r, int v)
{
	node *t1 = NULL, *t2 = NULL, *t3 = NULL;

	split(t, l, t1, t2);
	split(t2, r-l+1, t2, t3);

	t2->lazy += v;

	merge(t, t1, t2);
	merge(t, t, t3);
}

int query(node_t t, int l, int r)
{
	node *t1 = NULL, *t2 = NULL, *t3 = NULL;

	split(t, l, t1, t2);
	split(t2, r-l+1, t2, t3);

	int ans = t2->soma;

	merge(t, t1, t2);
	merge(t, t, t3);

	return ans;
}
