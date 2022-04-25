#include <bits/stdc++.h>

using namespace std;

int MX = 2e9;

bool dfs(long long u) {
    if (visited[u] == true) return false;
    visited[u] = true;

    if (changed[u] == true) return true;

    for (auto v : adj[u]) {
        if (dfs(v) == true) return true;
        else continue;
    }
    return false;
}

void Bellman-Ford(int n) {
    vector<vector<int> > adj;
    vector<bool> visited;
    vector<pair<pair<int, int>, int> > edges;
    vector<long long> dist(n, -MX);
    vector<bool> changed;

    dist[0] = 0;

    for (long long i = 0; i<n; i++) {
        for (auto e : edges) {
            long long a = e.first.first, b = e.first.second, w = e.second;

            dist[b] = max(dist[b], dist[a]+w);
        }
    }

    for (auto e : edges) {
        long long a = e.first.first, b = e.first.second, w = e.second;

        if (dist[b] == -2e18) continue;

        if (dist[a] + w > dist[b]) {
            changed[b] = true;
            dist[b] = dist[a] + w;
        }
    }


    adj.resize(n);
    visited.resize(n, false);
    for (auto e : edges) adj[e.first.second].push_back(e.first.first);

    if (dfs(n-1) == true) cout << -1;
    else cout << dist[n-1];
}

void DAG(int n, int m) {
    vector<vector<long long> > adj(n);
    vector<vector<long long> > prev(n);
    vector<long long> id(n, 0);

    vector<long long> dist(n, 0);
    vector<long long> p(n, -1);
    queue<long long> q;

    for (long long i = 0; i<n; i++) {
        if (id[i] == 0) q.push(i);
    }

    while(!q.empty()) {
        long long u = q.front(); q.pop();

        for (auto v : adj[u]) {
            id[v]--;
            if (id[v] == 0) q.push(v);
        }

        long long mx = -MX;
        long long prev_node = -1;
        for (auto v : prev[u]) {
            if (dist[v] + 1 > mx) {
                mx = dist[v] + 1;
                prev_node = v;
            }
        }

        dist[u] = mx;
        if (u == 0) dist[u] = 1;
        p[u] = prev_node;
    }

    stack<long long> ans;
    long long temp = n-1;
    bool possible = false;
    if (temp == 0) possible = true;

    while(temp != -1 && dist[temp] >= 0) {
        ans.push(temp);
        temp = p[temp];
        if (temp == 0) possible = true;
    }

    if (possible == false) cout << "IMPOSSIBLE";
    else {
        cout << dist[n-1] << '\n';
        while(!ans.empty()) {
            cout << ans.top()+1 << ' ';
            ans.pop();
        }
    }
}

int main()
{
	cin.tie(0);

	cout << "Longest Path" << endl;

	return 0;
}
