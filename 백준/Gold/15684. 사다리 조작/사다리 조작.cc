#include <iostream>
#include <vector>

using namespace std;;

int N; // 세로선의 개수
int M; // 가로선의 개수
int H; // 세로선마다 가로선을 놓을 수 있는 위치의 개수
bool isLinked[11][31]; // row번 세로줄과 row+1 세로줄이 column가로줄로 연결 되었는가?
int c = 4;

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

void dfs(int cnt, int maxcnt) {
	if (c != 4) return;
	if (maxcnt == cnt) {
		if (ladderGame()) c = min(c, cnt);
		return;
	}

	for (int i = 1; i < N; i++) {
		for (int j = 1; j <= H; j++) {
			if (isLinked[i][j] || isLinked[i - 1][j] || isLinked[i + 1][j]) continue;
			isLinked[i][j] = true;
			dfs(cnt + 1, maxcnt);
			isLinked[i][j] = false;
			while (!isLinked[i-1][j] && !isLinked[i+1][j]) j++;
		}
	}
	
}
void solve() {
	for (int i = 0; i < 4; i++) {
		dfs(0, i);
		if (c != 4) {
			cout << c;
			break;
		}
	}
	if (c == 4) cout << -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	input();
	solve();
	
	return 0;
}