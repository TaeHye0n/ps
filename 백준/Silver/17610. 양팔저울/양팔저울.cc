#include <iostream>

using namespace std;

int k;
int sum;
int arr[14];
bool visited[2600001];
int ans;

void input() {
	cin >> k;
	for (int i = 0; i < k; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
}

void solve(int n, int cur) {
	if (cur >= 1) {
		if (!visited[cur]) ans++;
		visited[cur] = true;
	}
	if (n == k) return;
	solve(n + 1, cur + arr[n]);
	solve(n + 1, cur);
	solve(n + 1, cur - arr[n]);
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	input();
	solve(0, 0);
	cout << sum - ans;
	return 0;
}