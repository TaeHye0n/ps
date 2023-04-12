#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N; // 건물의 개수 1000
int K; // 규치 개수 100,000
int delay[1001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin >> T;

	while (T--) {
		int answer = 0;
		cin >> N >> K;
		int inDegree[1001] = { 0, };
		int dp[1001] = { 0, };
		vector<int> graph[1001];

		for (int i = 1; i <= N; i++) {
			int temp;
			cin >> temp;
			delay[i] = temp;
			dp[i] = temp;
		}

		for (int i = 0; i < K; i++) {
			int from, to;
			cin >> from >> to;
			graph[from].push_back(to);
			inDegree[to]++;
		}
		int W = 0;
		cin >> W;

		queue<int> q;
		for (int i = 1; i <= N; i++) {
			if (inDegree[i] == 0) q.push(i);
		}

		while (!q.empty()) {
			int cur = q.front();
			q.pop();
			if (cur == W) {
				cout << dp[cur] << "\n";
				break;
			}
			for (int i = 0; i < graph[cur].size(); i++) {
				int next = graph[cur][i];
				dp[next] = max(dp[next], delay[next] + dp[cur]);
				if (--inDegree[next] == 0) {
					q.push(next);
				}
			}
		}
	}
	return 0;
}