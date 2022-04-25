#include <bits/stdc++.h>

using namespace std;

void Longest-Incresing-Subsequence(int n) {
    vector<int> v(n);
    vector<int> dp;

    for (auto x : v) {
        int pos = lower_bound(dp.begin(), dp.end(), x) - dp.begin();

        if (pos == dp.size()) dp.push_back(x);
        else dp[pos] = x;
    }

    return;
}

int main()
{
	cin.tie(0);

	cout << "Longest Incresing Subsequence" << endl;

	return 0;
}
