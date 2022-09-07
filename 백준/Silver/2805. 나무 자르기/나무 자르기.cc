#include<iostream>
#include<algorithm>
#include <climits>
using namespace std;

long long n, m, ans;
int arr[1000001];

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

void solve() {
	long long max = 0;
	long long left = 0;
	long long right = LLONG_MAX;
	
	while (left <= right) {
		long long mid = (left + right) / 2;
		long long res = 0;

		for (int i = 0; i < n; i++) {
			if (arr[i] - mid > 0) {
				res += arr[i] - mid;
			}
		}
		if (res >= m) {
			left = mid + 1;
			if (mid > max) max = mid;
		}
		else right = mid - 1;
	}
	cout << max << endl;
}
int main() {

	input();
	solve();
	return 0;
}