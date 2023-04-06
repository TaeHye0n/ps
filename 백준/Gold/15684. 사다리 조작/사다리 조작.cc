#include <iostream>
#include <vector>

using namespace std;

const int INF = 987654321;

int N; // 세로선의 개수
int M; // 가로선의 개수
int H; // 세로선마다 가로선을 놓을 수 있는 위치의 개수
bool isLinked[11][31]; // row번 세로줄과 row+1 세로줄이 column가로줄로 연결 되었는가?
int ans = INF;

void input() {
	cin >> N >> M >> H;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		isLinked[b][a] = true;
	}
}
bool ladderGame() {
	for (int i = 1; i <= N; i++) {
		int cur = i;
		for (int j = 1; j <= H; j++) {
			if (isLinked[cur][j]) cur++;
			else if (isLinked[cur - 1][j]) cur--;
		}
		if (cur != i) return false;
	}
	return true;
}

void recur(int idx, int cnt) {
	if (cnt >= 4) return;
	if (ladderGame()) {
		ans = min(ans, cnt);
		return;
	}

	for (int i = idx; i <= H; i++) {
		for (int j = 1; j < N; j++) {
			if (isLinked[j][i] || isLinked[j - 1][i] || isLinked[j + 1][i])continue;
			isLinked[j][i] = true;
			recur(i, cnt + 1);
			isLinked[j][i] = false;
		}
	}
}
void solve() {
	recur(1, 0);
	if (ans == INF) cout << -1;
	else cout << ans;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	input();
	solve();
	
	return 0;
}