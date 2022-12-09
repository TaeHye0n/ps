#include <iostream>
#include <vector>
using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int n;
	cin >> n;
	int x, y, z;
	int t = 0;
	int maxDp[2][3] = {};
	int minDp[2][3] = {};

	for (int i = 0; i < n; i++) {
		cin >> x >> y >> z;

		maxDp[t][0] = max(maxDp[1 - t][0], maxDp[1 - t][1]) + x;
		maxDp[t][1] = max(maxDp[1 - t][0], max(maxDp[1 - t][1], maxDp[1 - t][2])) + y;
		maxDp[t][2] = max(maxDp[1 - t][1], maxDp[1 - t][2]) + z;

		minDp[t][0] = min(minDp[1 - t][0], minDp[1 - t][1]) + x;
		minDp[t][1] = min(minDp[1 - t][0], min(minDp[1 - t][1], minDp[1 - t][2])) + y;
		minDp[t][2] = min(minDp[1 - t][1], minDp[1 - t][2]) + z;

		t = 1 - t;
	}

	cout << max(maxDp[1 - t][0], max(maxDp[1 - t][1], maxDp[1 - t][2])) << ' ';
	cout << min(minDp[1 - t][0], min(minDp[1 - t][1], minDp[1 - t][2]));
	return 0;
}