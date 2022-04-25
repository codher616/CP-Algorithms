#include <bits/stdc++.h>

using namespace std;

void SumOfTwo(int n, int x) {
    /// Reeturn the position of the two integers that sum up to x
    vector<pair<int, int> > v;
    for (int i = 0; i<n; i++) {
        int a;
        cin >> a;

        v.push_back(make_pair(a, i+1));
    }

    sort(v.begin(), v.end());

    int b = 0, e = n-1;

    while(b < e) {
        int a = v[b].first, z = v[e].first;

        if (a + z == x) {
            cout << min(v[b].second, v[e].second) << ' ' << max(v[b].second, v[e].second);
            return 0;
        } else if (a + z > x) e--;
        else b++;
    }

    cout << "IMPOSSIBLE";
    return;
}

int main()
{
	cin.tie(0);

	cout << "Two Pointers" << endl;

	return 0;
}
