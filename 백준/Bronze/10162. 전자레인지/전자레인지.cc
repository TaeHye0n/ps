#include <iostream>

using namespace std;

int A = 5 * 60;
int B = 1 * 60;
int C = 10;
int cnt[3];
int inputTime;

void input() {
	cin >> inputTime;
}

bool solve() {

	while (inputTime > 0) {
		if (inputTime % 10 != 0) {
			return false;
		}

		if (inputTime / A != 0) {
			cnt[0] += inputTime / A;
			inputTime %= A;
		}
		else if (inputTime / B != 0) {
			cnt[1] += inputTime / B;
			inputTime %= B;
		}
		else if (inputTime / C != 0) {
			cnt[2] += inputTime / C;
			inputTime %= C;
		}

	}
	return true;
}
int main() {
	input();
	if (solve()) {
		for (int i = 0; i < 3; i++) {
			cout << cnt[i] << ' ';
		}
	}
	else cout << -1;
	return 0;
}