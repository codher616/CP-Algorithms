#include <bits/stdc++.h>

using namespace std;

void Prim(int n) {
    vector<vector<pair<long long, long long> > > adj(n);
    vector<bool> visited(n, false);
    priority_queue<pair<long long, long long> > q;
    long long ans = 0;

    q.push({0, 0});
    while(!q.empty()) {
        long long u = q.top().second, w = -q.top().first; q.pop();

        if (visited[u] == true) continue;
        visited[u] = true; ans += w;

        for (auto [v, w] : adj[u]) q.push({-w, v});
    }

    bool possible = true;
    for (auto x : visited) if (x == false) possible = false;

    if (possible) cout << ans;
    else cout << "IMPOSSIBLE";

    return;
}

void Kruskal(int n) {
    vector<pair<int, pair<int, int> > edges(n);
    vector<int> UnionFind(n);
    vector<int> Sizes(n, 1);
    vector<bool> visited(n, false);

    sort(edges.begin(), edges.end());

    ans = 0;
    for (auto p : edges) {
        int w = p.first, a = p.second.first, b = p.second.second;
        if (UnionFind[a] != UnionFind[b]) {
            unite(a, b);
            ans = max(Sizes[a], Sizes[b]);
        }
    }
}

int main()
{
	cin.tie(0);

	cout << "Minimum Spanning Tree" << endl;

	return 0;
}
