#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N; // 가수의 수 1000
int M; // 보조 PD의 수 100
int indegree[1001];
vector<int> graph[1001];
vector<int> answer;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int cnt = 0;
		cin >> cnt;
		vector<int> temp;
		while (cnt--) {
			int a = 0;
			cin >> a;
			temp.push_back(a);
		}
		for (int j = 0; j < temp.size()-1; j++) {
			graph[temp[j]].push_back(temp[j + 1]);
			indegree[temp[j + 1]]++;
		}
	}
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) q.push(i);
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		answer.push_back(cur);

		for (int i = 0; i < graph[cur].size(); i++) {
			int next = graph[cur][i];
			if (--indegree[next] == 0) {
				q.push( next);
			}
		}
	}

	if (answer.size() == N) {
		for (int i = 0; i < answer.size(); i++) {
			cout << answer[i] << "\n";
		}
	}
	else cout << 0;
	return 0;
}