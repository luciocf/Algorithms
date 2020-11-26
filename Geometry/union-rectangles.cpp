// Area of Union of Rectangles
// O(n log maxc)

// This implementantion assumes the y-coordinates are in [0, 2e6]. If not, compress coordinates.

#include <bits/stdc++.h>

#define ff first
#define ss second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

const int maxn = 2e6+10;

struct SegmentTree
{
	pii tree[4*maxn];
	int lazy[4*maxn];

	void build(int node, int l, int r)
	{
		tree[node] = {0, r-l+1};
		if (l == r) return;

		int mid = (l+r)>>1;

		build(2*node, l, mid); build(2*node+1, mid+1, r);
	}

	void flush(int node, int l, int r)
	{
		if (!lazy[node]) return;

		if (l != r)
		{
			lazy[2*node] += lazy[node];
			lazy[2*node+1] += lazy[node];
		}

		tree[node].ff += lazy[node];
		lazy[node] = 0;
	}

	void upd(int node, int l, int r, int a, int b, int v)
	{
		flush(node, l, r);
		if (l > b || r < a) return;

		if (l >= a && r <= b)
		{
			lazy[node] = v;
			flush(node, l, r);
			return;
		}

		int mid = (l+r)>>1;

		upd(2*node, l, mid, a, b, v); upd(2*node+1, mid+1, r, a, b, v);

		tree[node].ff = min(tree[2*node].ff, tree[2*node+1].ff);
		tree[node].ss = 0;

		if (tree[2*node].ff == tree[node].ff) tree[node].ss += tree[2*node].ss;
		if (tree[2*node+1].ff == tree[node].ff) tree[node].ss += tree[2*node+1].ss;
	}
} seg;

struct Event
{
	int x, l, r, t; // x-coord, interval of y-coords, type of event (open/close)
} event[maxn];

bool comp(Event a, Event b)
{
	return a.x < b.x;
}

int main(void)
{
	int n;
	scanf("%d", &n);

	for (int i = 1; i <= n; i++)
	{
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

		event[2*i-1] = {x1, y1, y2, 0};
		event[2*i] = {x2, y1, y2, 1};
	}

	sort(event+1, event+2*n+1, comp);

	seg.build(1, 0, maxn-1);
	ll ans = 0;

	for (int i = 1; i <= 2*n; i++)
	{
		int x = event[i].x, l = event[i].l, r = event[i].r;

		if (i > 1)
		{
			seg.flush(1, 0, maxn-1);

			ans += (1ll*(x-event[i-1].x)*(maxn-seg.tree[1].ss));
		}

		seg.upd(1, 0, maxn-1, l+1, r, (event[i].t ? -1 : 1));
	}

	printf("%lld\n", ans);
}
