#include <iostream>
#include <vector>

#define INF 987654321

using namespace std;

int N; // 회원수 max 50
int graph[51][51];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	cin >> N;
	while (1) {
		int a, b;
		cin >> a >> b;
		if (a == -1 && b == -1)break;
		graph[a][b] = 1;
		graph[b][a] = 1;
	}

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j) graph[i][j] = 0;
			else if (graph[i][j] != 1) graph[i][j] = INF;
		}
	}

	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
			}
		}
	}
	int point = 51;
	int candidate = 0;
	for (int i = 1; i <= N; i++) {
		int temp = 0;
		for (int j = 1; j <= N; j++) {
			temp = max(temp, graph[i][j]);
		}
		point = min(point, temp);
	}
	vector<int> v;
	for (int i = 1; i <= N; i++) {
		int temp = 0;
		for (int j = 1; j <= N; j++) {
			temp = max(temp, graph[i][j]);
		}
		if (point == temp) {
			candidate++;
			v.push_back(i);
		}
	}
	cout << point << " " << candidate << "\n";
	for (auto i : v) {
		cout << i << " ";
	}
	return 0;
}