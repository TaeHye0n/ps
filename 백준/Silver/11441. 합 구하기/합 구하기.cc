#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N;
	cin >> N;
	
	vector<int> v(N + 1);
	int a = 0;
	for (int i = 1; i <= N; i++) {
		int b = 0;
		cin >> b;
		a += b;
		v[i] = a;
	}

	int M;
	cin >> M;
	while (M--) {
		int x, y;
		cin >> x >> y;
		cout << v[y] - v[x - 1] << "\n";
	}
	return 0;
}