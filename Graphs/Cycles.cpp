#include <bits/stdc++.h>

using namespace std;

int MX = 2e9;

void NegativeCycle(int n, int m) {
    vector<pair<pair<int, int>, int> > edges;
    vector<int> dist(n, MX);
    vector<int> p(n, -1);
    vector<int> ans;

    dist[0] = 0;
    int x;
    for (int i = 0; i<n; i++) {
        x = -1;
        for (auto e : edges) {
            int a = e.first.first, b = e.first.second, w = e.second;
            if (dist[a]+w < dist[b]) {
                x = b;
                dist[b] = dist[a]+w;
                p[b] = a;
            }
        }
    }

    if (x != -1) {
        cout >> "There is a cycle"
        for (int i = 0; i<n; i++) {
            x = p[x];
        }

        for (int v = x; ; v = p[v]) {
            ans.push_back(v);
            if (v == x && ans.size() > 1) break;
        }

    } else cout << "There is no cycle";

    return 0;
}

int n, m;
vector<vector<int> > adj;
vector<bool> visited;
stack<int> s;
vector<int> ans;

bool UndirectedGraph(int u, int p) {
    s.push(u);
    visited[u] = true;

    for (auto v : adj[u]) {
        if (v == p) continue;

        if (ans.size() > 0) return false;

        if (visited[v] == true) {
            s.pop();
            ans.push_back(v);
            ans.push_back(u);
            return true;
        }

        if (TSdfs(v, u) == true) {
            ans.push_back(u);
            s.pop();
            if (ans[0] == u) return false;
            else return true;
        } else if (ans.size() > 0) return false;
        else continue;
    }
    s.pop();
    return false;
}

vector<vector<int> > adj;
vector<bool> visited;
vector<bool> s;
vector<int> ans;

bool DirectedGraph(int u) {
    if (visited[u] == true) return false;
    visited[u] = true; s[u] = true;

    for (auto v : adj[u]) {
        if (ans.size() > 0) return false;

        if (s[v] == true) {
            ans.push_back(v);
            ans.push_back(u);
            s[u] = s[v] = false;
            return true;
        }

        if (visited[v] == true) continue;

        if (dfs(v) == true) {
            if (s[u] == true) {
                s[u] = false;
                ans.push_back(u);
                return true;
            } else {
                ans.push_back(u);
                return false;
            }
        } else continue;
    }
    s[u] = false;
    return false;
}

int n;
vector<int> destination;
vector<bool> visited;
vector<int> pathlength;
queue<int> path;
int steps = 0;

void dfs(int u) {
    path.push(u);
    if (visited[u] == true) {
        steps += pathlength[u];
        return;
    }

    visited[u] = true;
    steps++;

    dfs(destination[u]);
}

void CycleLengthFunctionalGraph(int n) {
    destination.resize(n);
    pathlength.resize(n, 0);
    visited.resize(n, false);

    for (int i = 0; i<n; i++) {
        cin >> destination[i];
        destination[i]--;
    }

    for (int i = 0; i<n; i++) {
        if (visited[i] == true) continue;
        steps = 0;
        dfs(i);

        int decrement = 1;
        while(!path.empty()) {
            int u = path.front();
            if (u == path.back()) decrement = 0;
            pathlength[u] = steps;
            steps -= decrement;
            path.pop();
        }
    }

    for (int i = 0; i<n; i++) cout << pathlength[i] << ' ';
    return 0;
}

void FloydAlgorithm(int n, int x) {
    vector<int> succ(n);

    int a = succ[x];
    int b = succ[succ[x]];
    while(a != b) {
        a = succ[a];
        b = succ[succ[b]];
    }

    a = x;
    while(a != b) {
        a = succ[a];
        b = succ[succ[b]];
    }
    int first = a;

    b = succ[first];
    int length = 1;
    while(a != b) {
        b = succ[b];
        length++;
    }
}

int main()
{
	cin.tie(0);

	cout << "Cycles" << endl;

	return 0;
}
