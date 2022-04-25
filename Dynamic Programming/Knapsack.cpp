#include <bits/stdc++.h>

using namespace std;

int MX = 1e5;

void Kanpsack(int n, int x)
{
    vector<pair<int, int> > v(n+1);

    vector<vector<int> > dp(n+1, vector<int> (x+1, 0));
    dp[0][0] = 0;

    for (int i = 1; i<=n; i++) {
        for (int j = 0; j<=x; j++) {
            dp[i][j] = dp[i-1][j];
            if (v[i].first <= j) dp[i][j] = max(dp[i-1][j], dp[i-1][j-v[i].first] + v[i].second);
        }
    }

    return;
}

void AllPosibleSums(int n) {
    vector<long long> v(n+1);

    sort(v.begin(), v.end());

    vector<vector<bool> > dp(n+1, vector<bool> (MX, false));
    dp[0][0] = true;

    for (long long i = 1; i<=n; i++) {
        for (long long j = 0; j<=MX; j++) {
            dp[i][j] = dp[i-1][j];
            if (j >= v[i]) if (dp[i-1][j-v[i]] == true) dp[i][j] = true;
        }
    }

    vector<int> ans;
    for (long long i = 1; i<=MX; i++) if (dp[n][i] == true) ans.push_back(i);

    return;
}

int main()
{
	cin.tie(0);

	cout << "Knapsack" << endl;

	return 0;
}
