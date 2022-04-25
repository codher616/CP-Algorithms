#include <bits/stdc++.h>

using namespace std;

void BJ(int n, int queries) {
    const int MXD = 30, MXN = 2e5+5;
    int parent[MXN][MXD]; // assign parent[i][0] for every i

    for (int j = 1; j<MXD; j++) {
        for (int i = 1; i<=n; i++) {
            parent[i][j] = parent[parent[i][j-1]][j-1];
        }
    }

    while(queries--) {
        int x, jumps;
        for (int i = 0; i<MXD; i++) {
            if (jumps & (1<<i)) x = parent[x][i];
        }
        int ans = x;
    }
}

int main()
{
	cin.tie(0);

	cout << "Binary Jumping" << endl;

	return 0;
}
