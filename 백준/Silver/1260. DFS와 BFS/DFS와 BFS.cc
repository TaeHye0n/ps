#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 1001

using namespace std;

int N, M, V;
bool vi[MAX];
vector<vector<int>> v(MAX);


void dfs(int start) {
	vi[start] = true;
	cout << start << " ";

	for (int i = 0; i < v[start].size(); i++) {
		if (!vi[v[start][i]]) {
			dfs(v[start][i]);
		}
	}
}

void bfs() {
	queue<int> q;
	q.push(V);
	vi[V] = true;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		cout << cur << " ";

		for (int i = 0; i < v[cur].size(); i++) {
			if (!vi[v[cur][i]] && v[cur][i] > 0) {
				q.push(v[cur][i]);
				vi[v[cur][i]] = true;
			}
		}
	}
}

void input() {
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		int from, to = 0;
		cin >> from >> to;
		v[from].push_back(to);
		v[to].push_back(from);
	}
}

int main() {
	input();
	for (int i = 0; i < v.size(); i++) {
		sort(v[i].begin(), v[i].end());
	}
	dfs(V);
	memset(vi, false, sizeof(vi));
	cout << "\n";
	bfs();
	return 0;
}