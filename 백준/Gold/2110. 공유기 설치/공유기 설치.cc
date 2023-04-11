#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N; // 집의 개수
int C; // 공유기의 개수
vector<int> home;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int ans = 0;
	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		home.push_back(temp);
	}
	sort(home.begin(), home.end());
	int l = 1; // 최소 간격
	int r = home.back() - home.front(); // 최대 간격
	while (l <= r) {
		int mid = (l + r) / 2;
		int routerNum = 1;
		int stRouter = home[0];

		for (int i = 1; i < N; i++) {
			if (home[i] - stRouter >= mid) {
				routerNum++;
				stRouter = home[i];
			}
		}

		if (routerNum >= C) {
			l = mid + 1;
			ans = mid;
		}
		else {
			r = mid - 1;
		}
	}
	cout << ans;
	return 0;
}