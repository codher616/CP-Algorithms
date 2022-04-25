#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > adj;
vector<bool> visited;

void dfs(int u) {
    if (visited[u] == true) return;
    visited[u] = true;

    for (auto v : adj[u]) dfs(v);

    return;
}

void bfs() {
    queue<int> q;
    q.push(0);

    while(!q.empty()) {
        int u = q.front(0); q.pop();
        if (visited[u] == true) continue;
        visited[u] = true;

        for (auto v : adj[u]) {
            q.push(v);
        }
    }
    return;

}

int main()
{
	cin.tie(0);

	cout << "Graph Traversal" << endl;

	return 0;
}
