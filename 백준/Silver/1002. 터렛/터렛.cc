#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		int x1, y1, r1, x2, y2, r2;
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		int dist = (y1 - y2) * (y1 - y2) + (x1 - x2) * (x1 - x2);
		int radiusSum = (r1 + r2) * (r1 + r2);
		int radiusSub = (r1 - r2) * (r1 - r2);
		if (x1 == x2 && y1 == y2 && r1 == r2) cout << -1 << "\n";
		else {
			if (dist == radiusSum || dist == radiusSub) cout << 1 << "\n";
			else if (dist < radiusSum && dist > radiusSub) cout << 2 << "\n";
			else cout << 0 << "\n";
		}
	}
	return 0;
}