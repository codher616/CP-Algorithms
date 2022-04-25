#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > adj;
vector<bool> visited;
vector<int> child;
vector<int> mx_dist;
int dist = 0;

void dfs(int u, int p, int d) {
    if (visited[u] == true) return;
    visited[u] = true;
    dist += d;

    for (auto v : adj[u]) {
        if (v == p) continue;
        child[u]++;
        dfs(v, u, d+1);
    }
    if (p != -1) child[p] += child[u];
    return;
}

void calc(int u, int p) {
    if (visited[u] == true) return;
    visited[u] = true;

    if (p == -1) mx_dist[u] = dist;
    else mx_dist[u] = mx_dist[p] - (child[u]+1) + (n-child[u]-1);

    for (auto v : adj[u]) {
        calc(v, u);
    }
    return;
}

void TSD(int n) {
    adj.resize(n);
    visited.resize(n, false);
    child.resize(n);
    mx_dist.resize(n, 0);

    dfs(0, -1, 0);

    visited.assign(n, false);

    calc(0, -1);

    vector<int> ans;
    for (auto x : mx_dist) ans.push_back(x);

    return;
}

int main()
{
	cin.tie(0);

	cout << "Tree Sum Distances" << endl;

	return 0;
}
