#include <iostream>

using namespace std;

const int MAX = 1e6 + 1;
int M, N;
int arr[MAX];

void input() {
	cin >> M >> N;
}

void solve() {
	for (int i = 2; i <= N; i++) {
		if (i == 1) continue;
		arr[i] = i;
	}

	for (int i = 2; i * i <= N; i++) {
		if (arr[i] != 0) {
			for (int j = i * 2; j <= N; j += i) {
				arr[j] = 0;
			}
		}
	}

	for (int i = M; i <= N; i++) {
		if (arr[i] != 0) cout << i << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	input();
	solve();
}