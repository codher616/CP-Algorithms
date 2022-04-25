#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<vector<int> > adj;
vector<bool> visited;
vector<int> TS;

int TSdfs(int u) {
    ///At the end, check if the topological sort was correct
    visited[u] = true;

    for (auto v : adj[u]) {
        if (visited[v] == true) continue;
        TSdfs(v);
    }

    TS.push_back(u);
    return;
}

void TSbfs(int n, int m) {
    vector<vector<int> > adj;
    vector<int> indegree;
    vector<int> TS;

    queue<int> q;
    for (int i = 0; i<n; i++) if (indegree[i] == 0) q.push(i);

    while(!q.empty()) {
        int u = q.front(); q.pop();

        for (auto v : adj[u]) {
            indegre[v]--;
            if (indegree[v] == 0) q.push(v);
        }

        TS.push_back(u);
    }
    return;
}

int main()
{
	cin.tie(0);

	cout << "Topological Sorting" << endl;

	return 0;
}
