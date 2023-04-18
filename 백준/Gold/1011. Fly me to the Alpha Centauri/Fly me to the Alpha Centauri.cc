#include <iostream>
#include <cmath>

typedef long long ll;
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T = 0;
	cin >> T;
	while (T--) {
		ll x = 0, y = 0;
		cin >> x >> y;
		ll cnt = 0;

		ll dist = y - x;
		ll max = floor(sqrt(dist));
		cnt = 2 * max - 1;
		ll left = dist - max * max;
		left = ceil((double)left / max);
		cnt += left;
		cout << cnt << "\n";
	}
	
	return 0;
}