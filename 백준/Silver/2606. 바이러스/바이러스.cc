#include <iostream>
#include <queue>

using namespace std;
#define INF 987654321
int N; // 컴퓨터의 수 100 이하
int M; // 컴퓨터 쌍의 수
int coms[101][101];

void input() {
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (j == i) coms[i][j] = 0;
			else coms[i][j] = INF;
		}
	}
	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		coms[a][b] = 1;
		coms[b][a] = 1;
	}
}

void solve() {
	for(int k = 1; k<=N; k++){
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				coms[i][j] = min(coms[i][j], coms[i][k] + coms[k][j]);
			}
		}
	}
	int cnt = 0;
	for (int i = 2; i <= N; i++) {
		if (coms[1][i] != INF) cnt++;
	}
	cout << cnt;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	input();
	solve();
	return 0;
}