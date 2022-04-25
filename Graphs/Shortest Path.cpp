    #include <bits/stdc++.h>

using namespace std;

int MX;

void unwheighted(int n, int m) {
    vector<int> dist(n, MX);
    vector<int> parent(n, 0);
    queue<int> q;
    dist[0] = 0; q.push(0);

    while(!q.empty()) {
        int u = q.front(); q.pop();

        for (auto v : adj[u]) {
            if (dist[v] != MX) continue;
            dist[v] = dist[u]+1;
            parent[v] = u;
            q.push(v);
        }
    }

    return;
}

void Dijkstra(int n, int m) {
    vector<vector<int> > adj(n);
    vector<bool> visited(n, false);
    vector<int> dist(n, MX);
    priority_queue<pair<long long, long long> > q;

    q.push(make_pair(0, 0));
    dist[0] = 0;

    while(!q.empty()) {
        long long u = q.top().second; q.pop();

        if (visited[u] == true) continue;
        visited[u] = true;

        for (auto p : adj[u]) {
            long long v = p.first, d = p.second;
            if (dist[u] + d < dist[v]) {
                dist[v] = dist[u]+d;
                q.push(make_pair(-dist[v], v));
            } else continue;
        }
    }
    return;
}

void Floyd-Wharshall(int n, int m) {
    vector<vector<long long> > matrix(n, vector<long long> (n, INF));
    vector<vector<long long> > dist(n, vector<long long> (n, INF));

    for (long long i = 0; i<n; i++) {
        for (long long j = 0; j<n; j++) {
            if (matrix[i][j] == -1) continue;
            if (i == j) dist[i][j] = 0;
            else dist[i][j] = matrix[i][j];
        }
    }

    for (long long k = 0; k<n; k++) {
        for (long long i = 0; i<n; i++) {
            for (long long j = 0; j<n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    return;
}

void Bellman-Ford(int n, int m) {
    vector<pair<pair<int, int>, int> > edges;
    vector<long long> dist(n, -MX);
    dist[0] = 0;

    for (long long i = 0; i<n; i++) {
        for (auto e : edges) {
            long long a = e.first.first, b = e.first.second, w = e.second;

            dist[b] = max(dist[b], dist[a]+w);
        }
    }
}

void K-shortest(int n, int m, int k) {
    vector<vector<pair<long long, long long> > > adj(n);
    vector<long long> cnt(n, 0);
    vector<long long> dist(n, MX);
    priority_queue<pair<long long, long long> > q;
    q.push({0, 0});
    dist[0] = 0;

    vector<long long> ans;
    while(!q.empty()) {
        long long u = q.top().second, d = q.top().first * -1; q.pop();

        if (u == n-1) ans.push_back(d);

        cnt[u]++;
        if (cnt[u] > k) continue;

        for (auto [v, w] : adj[u]) {
            q.push(make_pair(-(d+w), v));
        }
    }
    return;
}


int main()
{
	cin.tie(0);

	cout << "Shortest Path" << endl;

	return 0;
}
