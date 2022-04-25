#include <bits/stdc++.h>

using namespace std;

void MinimumSparseTable(int n) {
    vector<int> v;

    vector<int> log(n+1);
    log[1] = 0;
    for (int i = 2; i<=n; i++) log[i] = log[i/2]+1;
    int k = log[n];

    vector<vector<int> > st(n, vector<int> (k+1));
    for (int i = 0; i<n; i++) st[i][0] = v[i];

    for (int j = 1; j<=k; j++) {
        for (int i = 0; i+(1<<j)-1 < n; i++) {
            st[i][j] = min(st[i][j-1], st[i+(1<<(j-1))][j-1]);
        }
    }

    /// 0 indexed
    /// ans = min(st[a][log[mid]], st[b - (1<<mid)+1][log[mid]]

    return;
}

int main()
{
	cin.tie(0);

	cout << "Sparse Table" << endl;

	return 0;
}
