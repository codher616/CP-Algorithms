#include <bits/stdc++.h>

using namespace std;

void PermutationToSubsets(int n, int x) {
    vector<int> v(n);

    pair<int, int> best[1<<n];
    best[0] = {1, 0};

    for (int s = 1; s<(1<<n); s++) {
        best[s] = {n+1, 0};
        for (int p = 0; p<n; p++) {
            if (s&(1<<p)) {
                auto option = best[s^(1<<p)];
                if (option.second+v[p] <= x) option.second += v[p];
                else {
                    option.second = v[p];
                    option.first++;
                }
                best[s] = min(best[s], option);
            }
        }
    }

    cout << best[(1<<n) - 1].first;
}

int main()
{
	cin.tie(0);

	cout << "Bits Dynamic Programming" << endl;

	return 0;
}
