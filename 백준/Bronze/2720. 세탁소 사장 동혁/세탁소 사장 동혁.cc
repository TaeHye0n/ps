#include <iostream>

using namespace std;

int T;
int C;
int main() {
	cin >> T;
	while (T--) {
		cin >> C;
		int ans[4] = { 0,0,0,0 };
		while (C > 0) {
			if (C /25 > 0) {
				ans[0] = C / 25;
				C %= 25;
			}
			else if (C / 10 > 0) {
				ans[1] = C / 10;
				C %= 10;
			}
			else if (C / 5 > 0) {
				ans[2] = C / 5;
				C %= 5;
			}
			else {
				ans[3] = C / 1;
				C = 0;
			}
		}
		for (int i = 0; i < 4; i++) {
			cout << ans[i] << ' ';
		}
		cout << "\n";
	}
	return 0;
}