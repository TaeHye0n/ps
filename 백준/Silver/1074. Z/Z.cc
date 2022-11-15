#include <iostream>

using namespace std;


int N, r, c;
int ans;

void input() {
	cin >> N >> r >> c;
}

void dfs(int y, int x, int mySize) {
	if (y == r && x == c) {
		cout << ans;
		return;
	}

	if (r < y + mySize && r >= y && c < x + mySize && c >= x) {
		dfs(y, x, mySize / 2);
		dfs(y, x + mySize / 2, mySize / 2);
		dfs(y + mySize / 2, x, mySize / 2);
		dfs(y + mySize / 2, x + mySize / 2, mySize / 2);
	}
	else {
		ans += mySize * mySize;
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	input();
	dfs(0, 0, 1 << N);
	return 0;
}