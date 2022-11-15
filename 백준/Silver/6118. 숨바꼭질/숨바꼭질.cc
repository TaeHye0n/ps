#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<int> graph[20001];
int visited[20001];
int maxDist;

void input() {
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
}

void bfs() {
	queue<int> q;
	q.push(1);
	visited[1] = 0;
	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		for (int i = 0; i < graph[curr].size(); i++) {
			if (visited[graph[curr][i]] == -1) {
				visited[graph[curr][i]] = visited[curr] + 1;
				q.push(graph[curr][i]);
				maxDist = max(maxDist, visited[graph[curr][i]]);

			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	input();
	for (int i = 1; i <= N; i++) {
		visited[i] = -1;
	}

	bfs();
	int cnt = 0;
	int idx = 0;
	for (int i = 1; i <= N; i++) {
		if (visited[i] == maxDist) cnt++;
	}
	for (int i = 1; i <= N; i++) {
		if (visited[i] == maxDist) {
			idx = i;
			break;
		}
	}
	cout << idx << " " << maxDist << " " << cnt;
}