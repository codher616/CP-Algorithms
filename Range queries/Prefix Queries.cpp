#include <bits/stdc++.h>

using namespace std;

void PrefixSums(int n) {
    vector<int> v(n+1);
    vector<int> ps(n+1, 0);
    for (int i = 1; i<=n; i++) ps[i] = ps[i-1] + v[i];
    /// ans = ps[b] - ps[a-1]
}

void PrefixSums2D(int n) {
    vector<vector<int> > matrix(n+1, vector<int> (n+1));
    vector<vector<int> > ps(n+1, vector<int> (n+1, 0));

    for (int i = 1; i<=n; i++) {
        for (int j = 1; j<=n; j++) {
            ps[i][j] = ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1] + matrix[i][j];
        }
    }
    /// ans = ps[y1][x1] - ps[y1][x0-1] - ps[y0-1][x1] + ps[y0-1][x0-1]
}

void PrefixXor(int n) {
    vector<int> v(n+1);
    vector<int> px(n+1);
    px[1] = v[1];
    for (int i = 2; i<=n; i++) px[i] = px[i-1]^v[i];
    /// ans = px[a-1]^px[b]
}

int main()
{
	cin.tie(0);

	cout << "Prefix Queries" << endl;

	return 0;
}
