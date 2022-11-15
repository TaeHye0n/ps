#include <iostream>

using namespace std;

int M, N;
void input() {
	cin >> M >> N;
}

void solve() {
	for (int i = M; i <= N; i++) {
		if (i == 1) continue;
		if (i == 2) cout << 2 << "\n";
		else {
			bool flag = false;
			for (int j = 2; j * j <= i; j++) {
				if (i % j == 0) flag = true;
			}
			if (!flag) cout << i << "\n";
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	input();
	solve();
}