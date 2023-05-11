#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 10001
using namespace std;

int N, M;
vector<int> graph[MAX];
bool visited[MAX];
vector<pair<int, int>> res;
int cnt = 0;

bool cmp(pair<int, int> p1, pair<int, int> p2) {
	if (p1.first == p2.first) return p1.second < p2.second;
	return p1.first > p2.first;
}
void dfs(int st) {
	cnt++;
	visited[st] = true;
	for (int i = 0; i < graph[st].size(); i++) {
		int next = graph[st][i];
		if (!visited[next]) {
			dfs(next);
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		graph[b].push_back(a);
	}

	for (int i = 1; i <= N; i++) {
		dfs(i);
		memset(visited, false, sizeof(visited));
		res.push_back({ cnt,i });
		cnt = 0;
	}

	sort(res.begin(), res.end(), cmp);
	cout << res[0].second << " ";
	for (int i = 1; i < res.size(); i++) {
		if (res[0].first > res[i].first) break;
		cout << res[i].second << " ";
	}
	
	return 0;
}