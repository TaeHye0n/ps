#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> coordinate;
int N, K;
int ans;

void input() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int temp = 0;
		cin >> temp;
		coordinate.push_back(temp);
	}
}

void solve() {
	sort(coordinate.begin(), coordinate.end());
	vector<int> dist;
	for (int i = 0; i < coordinate.size() - 1; i++) {
		int temp = coordinate[i + 1] - coordinate[i];
		dist.push_back(temp);
	}
	sort(dist.begin(), dist.end());
	for (int i = 0; i < N - K; i++) {
		ans += dist[i];
	}
}

int main() {
	input();
	solve();
	cout << ans;
	return 0;
}