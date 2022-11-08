#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int T;
int N, M;

int main() {
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		int ans = 0;
		cin >> N >> M;
		vector<int> a(N);
		vector<int> b(M);

		for (int i = 0; i < N; i++) {
			cin >> a[i];
		}
		for (int i = 0; i < M; i++) {
			cin >> b[i];
		}

		sort(a.begin(), a.end());
		sort(b.begin(), b.end());

		int pointer = 0;
		for (int i = 0; i < N; i++) {
			while (pointer<M && a[i] > b[pointer]) {
				pointer++;
			}
			ans += pointer;
		}
		cout << ans << "\n";
	}
	return 0;
}