#include <iostream>
#include <vector>
using namespace std;

int N;
vector<pair<int, int>> v;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}
}

double outerProduct(double x1, double x2, double x3, double y1, double y2, double y3) {
	double product = (x1 * y2 + x2 * y3 + x3 * y1) - (x2 * y1 + x3 * y2 + x1 * y3);
	return product / 2;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	input();
	double ans = 0;

	for (int i = 1; i < N; i++) {
		ans += outerProduct(v[0].first, v[i - 1].first, v[i].first, v[0].second, v[i - 1].second, v[i].second);
	}

	cout.precision(1);
	cout << fixed;
	cout << abs(ans);

	return 0;
}