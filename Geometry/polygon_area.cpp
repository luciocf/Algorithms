// Area of a Simple Polygon (Shoelace Formula)
// O(n)

#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

const int MAXN = 1e5+10;

typedef pair<int, int> ponto;

int n;
ponto p[MAXN];

int cross(ponto a, ponto b)
{
    return a.x*b.y-a.y*b.x;
}

int area(void)
{
    double ans = 0.00;
    for (int i = 3; i <= n; i++)
    {
        ponto a = {p[i].x-p[1].x, p[i].y-p[1].y};
        ponto b = {p[i-1].x-p[1].x, p[i-1].y-p[1].y};

        ans += cross(a, b)/2.00;
    }

    return abs(ans);
}
