// 2D Segment Tree
// Update: O(log n log m)
// Query: O(log n log m)

#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e3+10;
const int MAXM = 1e3+10;

int tree[4*MAXN][4*MAXM], num[MAXN][MAXM], n, m;

void build_y(int nodex, int lx, int rx, int nodey, int ly, int ry)
{
	if (ly == ry)
	{
		if (lx == rx) tree[nodex][nodey] = num[lx][ly];
		else tree[nodex][nodey] = tree[2*nodex][nodey]+tree[2*nodex+1][nodey];
		return;
	}

	int my = (ly+ry)/2;

	build_y(nodex, lx, rx, 2*nodey, ly, my);
	build_y(nodex, lx, rx, 2*nodey+1, my+1, ry);

	tree[nodex][nodey] = tree[nodex][2*nodey]+tree[nodex][2*nodey+1];
}

void build_x(int nodex, int lx, int rx)
{
	if (lx == rx)
	{
		build_y(nodex, lx, rx, 1, 1, m);
		return;
	}

	int midx = (lx+rx)/2;

	build_x(2*nodex, lx, midx); 
	build_x(2*nodex+1, midx+1, rx);

	build_y(nodex, lx, rx, 1, 1, m);
}

void upd_y(int nodex, int lx, int rx, int nodey, int ly, int ry, int posy, int v)
{
	if (ly == ry)
	{
		if (lx == rx) tree[nodex][nodey] = v;
		else tree[nodex][nodey] = tree[2*nodex][nodey]+tree[2*nodex+1][nodey];
		return;
	}

	int my = (ly+ry)/2;

	if (posy <= my) upd_y(nodex, lx, rx, 2*nodey, ly, my, posy, v);
	else upd_y(nodex, lx, rx, 2*nodey+1, my+1, ry, posy, v);

	tree[nodex][nodey] = tree[nodex][2*nodey]+tree[nodex][2*nodey+1];
}

void upd_x(int nodex, int lx, int rx, int posx, int posy, int v)
{
	if (lx == rx)
	{
		upd_y(nodex, lx, rx, 1, 1, m, posy, v);
		return;
	}

	int mx = (lx+rx)/2;

	if (posx <= mx) upd_x(2*nodex, lx, mx, posx, posy, v);
	else upd_x(2*nodex+1, mx+1, rx, posx, posy, v);

	upd_y(nodex, lx, rx, 1, 1, m, posy, v);
}

int query_y(int nodex, int nodey, int ply, int pry, int ly, int ry)
{
	if (ply > ry || pry < ly) return 0;
	if (ply >= ly && pry <= ry) return tree[nodex][nodey];

	int my = (ply+pry)/2;

	int p1 = query_y(nodex, 2*nodey, ply, my, ly, ry);
	int p2 = query_y(nodex, 2*nodey+1, my+1, pry, ly, ry);

	return (p1+p2);
}

int query_x(int nodex, int plx, int prx, int lx, int rx, int ly, int ry)
{
	if (plx > rx || prx < lx) return 0;
	if (plx >= lx && prx <= rx) return query_y(nodex, 1, 1, m, ly, ry);

	int mx = (plx+prx)/2;

	int p1 = query_x(2*nodex, plx, mx, lx, rx, ly, ry);
	int p2 = query_x(2*nodex+1, mx+1, prx, lx, rx, ly, ry);

	return (p1+p2);
}
