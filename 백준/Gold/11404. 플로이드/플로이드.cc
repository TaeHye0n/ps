#include <iostream>
#define MAX 101
#define INF 987654321
using namespace std;

int n; // 도시의 개수
int m; // 버스의 개수
int dist[MAX][MAX];

void init() {
	for (int i = 1; i <=n ; i++) {
		for (int j =1 ; j <= n; j++) {
			if (i == j) dist[i][j] = 0;
			else dist[i][j] = INF;
		}
	}
}
void input() {
	cin >> n >> m;
	init();
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = min(dist[a][b], c);
	}
}
void solve() {

	for (int k = 1; k <= n; k++) {
		for (int j = 1; j <= n; j++) {
			for (int i = 1; i <= n; i++) {
				dist[j][i] = min(dist[j][i], dist[j][k] + dist[k][i]);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (dist[i][j] == INF) dist[i][j] = 0;
			cout << dist[i][j] << " ";
		}
		cout << "\n";
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