#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<pair<int, int>> cow;
void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		cow.push_back({ a,b });
	}
}

void solve() {
	sort(cow.begin(), cow.end());
	int time = cow[0].first + cow[0].second;
	for (int i = 1;i < cow.size(); i++) {
		if (cow[i].first <= time) {
			time += cow[i].second;
		}
		else time = cow[i].first + cow[i].second;
	}
	cout << time;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	input();
	solve();
	return 0;
}