#include <iostream>
#include <cmath>

using namespace std;

double x, y, c;

double calculate(double mid) {
	double xh = sqrt(x * x - mid * mid);
	double yh = sqrt(y * y - mid * mid);

	return (xh * yh) / (xh + yh);
}
void solve() {
	cin >> x >> y >> c;

	double L = 0;
	double R = min(x, y);

	double res = 0;

	while (L <= R) {
		double mid = (L + R) / 2;
		
		if (calculate(mid) >= c) {
			res = mid;
			L = mid + 0.000001;
		}
		else R = mid - 0.000001;
	}
	printf("%.3f\n", res);
}

int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);

	solve();

	return 0;
}