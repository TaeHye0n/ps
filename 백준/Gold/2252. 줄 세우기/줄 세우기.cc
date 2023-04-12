#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N; // 학생의 수 32,000
int M; // 키르 비교한 회수 100,000
vector<int> graph[32001];
int inserted[32001];
queue<int> q;
void input() {
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		graph[A].push_back(B);
		inserted[B]++;
	}
}

void solve() {
	for (int i = 1; i <= N; i++) {
		if (inserted[i] == 0) q.push(i);
	}
		
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		cout << cur << " ";
		for (int i = 0; i < graph[cur].size(); i++) {
			inserted[graph[cur][i]]--;
			if (inserted[graph[cur][i]] == 0) {
				q.push(graph[cur][i]);
			}
		}
	}

}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	input();
	solve();
	return 0;
}