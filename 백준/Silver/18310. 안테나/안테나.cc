#include <iostream>
#include <algorithm>

#define MAX 200001
using namespace std;

int N;
int house[MAX];

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> house[i];
	}
}

void solve() {
	int ans = 0;
	sort(house, house + N);
	ans = house[(N - 1) / 2];
	cout << ans;
}

int main() {
	input();
	solve();
	return 0;
}