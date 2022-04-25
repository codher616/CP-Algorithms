#include <bits/stdc++.h>

using namespace std;

int bs1(int high, int low, int ans) {
    while(low <= high) {
        int mid = low + (high-low)/2;s

        if (mid > ans) high = mid-1;
        else if (mid < ans) low = mid+1;
        else return mid;
    }

    return low;
}

int bs2(int high, int low, int ans) {
    // high must be at least the maximum number plus one
    while(high > low+1) {
        int mid = low + (high-low)/2;s

        if (mid > ans) high = mid;
        else if (mid < ans) low = mid;
        else return mid;
    }

    return low;
}

int leftmost(int l, int r, vector<int> v, int ans) {
    int mid = 0;
    while(r > l+1) {
        mid = l + (r-l)/2;

        if (v[mid] < ans) l = mid;
        else r = mid;
    }

    return mid;
}

int rightmost(int l, int r, vector<int> v, int ans) {
    int mid = 0;
    while(r > l+1) {
        mid = l + (r-l)/2;

        if (v[mid] > ans) r = mid;
        else l = mid;
    }

    return mid;
}

double float_numbers(double l, double r, double ans) {
    double mid = 0;

    for (int p = 0; p<100; p++) {
        mid = l + (r-l)/2;

        if (mid > ans) r = mid;
        else l = mid;
    }

    return mid;
}

int main()
{
	cin.tie(0);

	cout << "Binary Search" << endl;

	return 0;
}
