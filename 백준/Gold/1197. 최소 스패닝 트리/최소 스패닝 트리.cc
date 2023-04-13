#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int V; // 정점의 개수
int E; // 간선의 개수
vector<vector<int>> costs;
int parent[10001];
bool cmp(vector<int> v1, vector<int> v2) {
	return v1[2] < v2[2];
}

int find(int node) {
	if (node == parent[node]) return node;
	return parent[node] = find(parent[node]);
}
void Union(int A, int B) {
	A = find(A);
	B = find(B);
	parent[B] = A;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int answer = 0;

	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		vector<int> temp;
		for (int j = 0; j < 3; j++) {
			int a;
			cin >> a;
			temp.push_back(a);
		}
		costs.push_back(temp);
	}

	for (int i = 1; i <= V; i++) {
		parent[i] = i;
	}

	sort(costs.begin(), costs.end(), cmp);

	for (int i = 0; i < costs.size(); i++) {
		int A = costs[i][0];
		int B = costs[i][1];
		int cost = costs[i][2];

		if (find(A) != find(B)) {
			answer += cost;
			Union(A, B);
		}
	}
	cout << answer;
	return 0;
}