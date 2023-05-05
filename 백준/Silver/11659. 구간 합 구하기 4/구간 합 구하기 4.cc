#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int N, M;
	cin >> N >> M;
	int arr[100001] = { 0, };
	int psum[100001] = { 0, };

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
		psum[i] = psum[i - 1] + arr[i];
	}

	while (M--) {
		int i, j;
		cin >> i >> j;
		cout << psum[j] - psum[i - 1] << "\n";
	}
	return 0;
}