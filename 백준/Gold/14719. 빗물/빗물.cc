#include <iostream>

#define MAX 501
using namespace std;

int H, W;
int block[MAX];
int ans;

void input() {
	cin >> H >> W;
	for (int i = 0; i < W; i++) {
		cin >> block[i];
	}
}

void solve() {
	for (int i = 1; i < W-1; i++) {
		int left = 0, right = 0;
		for (int j = 0; j < i; j++) {
			left = max(left, block[j]);
		}
		for (int j = W - 1; j > i; j--) {
			right = max(right, block[j]);
		}
		ans += max(0, min(left, right) - block[i]);
	}
	cout << ans;
}
int main() {
	input();
	solve();
	return 0;
}