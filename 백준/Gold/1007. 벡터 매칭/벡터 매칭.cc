#include <iostream>
#include <vector>
#include <cmath>
#include <cfloat>

using namespace std;

int N; // 점의 개수
double ans;
pair<int, int> point[21];
bool visited[21];

double getNorm() {
	pair<int, int> st = { 0,0 };
	pair<int, int> dest = { 0,0 };

	for (int i = 0; i < N; i++) {
		if (visited[i]) {
			st.first += point[i].first;
			st.second += point[i].second;
		}
		else {
			dest.first += point[i].first;
			dest.second += point[i].second;
		}
	}
	return sqrt(pow(st.first - dest.first, 2) + pow(st.second - dest.second, 2));
}
void dfs(int cnt, int idx) {
	if (cnt == N/2) {
		ans = min(ans, getNorm());
		return;
	}

	for (int i = idx; i < N; i++) {
		if (!visited[i]) {
			visited[i] = true;
			dfs(cnt + 1, i);
			visited[i] = false;
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	int T;
	cin >> T;
	while (T--) {
		ans = DBL_MAX;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> point[i].first >> point[i].second;
		}
		dfs(0, 0);
		cout << fixed;
		cout.precision(7);
		cout << ans << "\n";
	}
	return 0;
}