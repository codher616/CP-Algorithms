#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > adj;
vector<int> dist;

void Dijkstra(int start) {
    priority_queue<pair<int, int> > q;
    q.push({0, start});
    dist[start] = 0;

    while(!q.empty()) {
        int u = q.top().second; q.pop();

        for (auto v : adj[u]) {
            if (dist[v] != -1) continue;
            dist[v] = dist[u]+1;
            q.push({-dist[v], v});
        }
    }
}

void TreeDiameter(int n) {
    adj.resize(n);
    dist.resize(n, -1);

    for (int i = 0; i<n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    Dijkstra(0);

    pair<int, int> mx = {0, 0};
    for (int i = 0; i<n; i++) {
        if (dist[i] > mx.second) {
            mx.first = i;
            mx.second = dist[i];
        }
    }

    dist.assign(n, -1);
    dijkstra(mx.first);

    int ans = 0;
    for (auto x : dist) ans = max(ans, x);

    return;
}

int main()
{
	cin.tie(0);

	cout << "Tree Diameter" << endl;

	return 0;
}
