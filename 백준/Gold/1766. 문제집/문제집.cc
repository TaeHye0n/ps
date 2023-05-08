#include <iostream>
#include <queue>

using namespace std;

int N; // 문제의 수
int M; // 정보의 개수
int indegree[32001];
vector<int> v[32001];
vector<int> ans;

void topology() {
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= N; i++) {
		if (indegree[i] == 0) pq.push(i);
	}

	while (!pq.empty()) {
		int cur = pq.top();
		ans.push_back(cur);
		pq.pop();

		for (int i = 0; i < v[cur].size(); i++) {
			int next = v[cur][i];
			if (--indegree[next] == 0) {
				pq.push(next);
			}
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	
	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		indegree[b]++;
	}

	topology();
	for (int num : ans) {
		cout << num << " ";
	}
	return 0;
}