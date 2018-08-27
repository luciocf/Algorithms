// Convex Hull
// O(n log n)

#include <bits/stdc++.h>
#define x first
#define y second

using namespace std;

const int MAXN = 1e5+10;

typedef pair<int, int> ponto;

vector<ponto> a;

int cross(ponto a, ponto b)
{
    return a.x*b.y-a.y*b.x;
}

bool ccw(ponto p, ponto q, ponto r)
{
    q.x -= p.x, q.y -= p.y;
    r.x -= p.x, r.y -= p.y;
    return (cross(q, r) > 0);
}

bool cw(ponto p, ponto q, ponto r)
{
    q.x -= p.x, q.y -= p.y;
    r.x -= p.x, r.y -= p.y;
    return (cross(q, r) < 0);
}

int main(void)
{
    sort(a.begin(), a.end());

    ponto p1 = a[0], p2 = a.back();
    vector<ponto> up, down;
    up.push_back(p1), down.push_back(p1);

    for (int i = 1; i < a.size(); i++)
    {
        if (i == a.size()-1 || cw(p1, a[i], p2))
        {
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size()-1 || ccw(p1, a[i], p2))
        {
            while (down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }
}
