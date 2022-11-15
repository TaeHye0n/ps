#include <iostream>

using namespace std;

int gcd(int a, int b) {
	if (a % b == 0) return b;
	return gcd(b, a % b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int arr[101] = {};
		long long ans = 0;
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				ans += gcd(arr[i], arr[j]);
			}
		}
		cout << ans << "\n";
	}
}