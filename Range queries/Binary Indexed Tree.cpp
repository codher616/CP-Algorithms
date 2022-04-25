#include <bits/stdc++.h>

using namespace std;

vector<int> v;
vector<int> bt;

void update(int k, int x) {
    while(k <= n) {
        bt[k] += x;
        k += k & -k;
    }
}

int sum(int k) {
    int s = 0;
    while(k >= 1) {
        s += bt[k];
        k -= k & -k;
    }
    return s;
}

void BIT(int n) {
    v.resize(n+1);
    bt.resize(n+1, 0);

    for (int i = 1; i<=n; i++) update(i, v[i]);

    /// 1 indexed
    /// update(pos, x-v[pos]; v[pos] = x;
    /// ans = sum(b) - sum(a-1)
}

int main()
{
	cin.tie(0);

	cout << "Binary Indexed Tree" << endl;

	return 0;
}
