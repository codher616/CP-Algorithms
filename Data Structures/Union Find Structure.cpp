#include <bits/stdc++.h>

using namespace std;

vector<int> parent;
vector<int> sz;

int findp(int u) {
    if (parent[u] != u) parent[u] = findp(parent[u]);
    return parent[u];
}

void unite(int u, int v) {
    int a = findp(u), b = findp(v);
    if (a == b) return;

    if (sz[a] < sz[b]) swap(a, b);
    s[a] += s[b];
    parent[b] = a;
    return;
}

bool same(int u, int v) {
    return findp(u) == findp(v);
}

int main()
{
	cin.tie(0);

	cout << "Union Find Structure" << endl;

	return 0;
}
