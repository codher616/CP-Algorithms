#include <bits/stdc++.h>

using namespace std;

vector<int> values;

int get_value(int x) {
    return lower_bound(values.begin(), values.end(), x) - values.begin();s
}

int main()
{
	cin.tie(0);

	cout << "Coordinate Compression" << endl;

	return 0;
}
