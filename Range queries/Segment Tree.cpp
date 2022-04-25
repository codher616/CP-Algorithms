#include <bits/stdc++.h>

using namespace std;

vector<int> v;
vector<int> t;
int MX = 2e9;

void build(int tv, int tl, int tr) {
    if (tl == tr) t[tv] = v[tl];
    else {
        int mid = tl + (tr-tl)/2;
        build(2*tv, tl, mid);
        build(2*tv+1, mid+1, tr);
        t[tv] = min(t[2*tv], t[2*tv+1]);
    }
}

int mn(int tv, int tl, int tr, int l, int r) {
    if (l > r) return MX;
    if (tl == l && tr == r) return t[tv];

    int mid = tl + (tr-tl)/2;
    return min(mn(2*tv, tl, mid, l, min(mid, r), mn(2*tv+1, mid+1, tr, max(mid+1, l), r)));
}

void update(int tv, int tl, int tr, int pos, int val) {
    if (tl == tr) t[tv] = val;
    else {
        int mid = tl + (tr-tl)/2;
        if (pos <= mid) update(2*tv, tl, mid, pos, val);
        else update(2*v+1, mid+1, tr, pos, val);
        t[tv] = min(t[2*tv], t[2*tv+1]);
    }
}

void MinimumSegmentTree(int n) {
    v.resize(n+1);
    t.resize(4*n+1);

    build(1, 0, n-1);

    /// 0 indexed
    /// update(1, 0, n-1, pos, val)
    /// mn(1, 0, n-1, a, b)
}

int main()
{
	cin.tie(0);

	cout << "Segment Tree" << endl;

	return 0;
}
