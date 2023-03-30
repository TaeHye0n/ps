#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int saw[4][8];
int K;
vector<pair<int, int>> cmd;

void rotate(int num, int dir) {
	if (dir == 1) {
		int temp = saw[num][7];
		for (int i = 7; i > 0; i--) {
			saw[num][i] = saw[num][i - 1];
		}
		saw[num][0] = temp;
	}

	else if (dir == -1) {
		int temp = saw[num][0];
		for (int i = 0; i < 7; i++) {
			saw[num][i] = saw[num][i + 1];
		}
		saw[num][7] = temp;
	}
	else return;
}

void solve() {
	for (int i = 0; i < K; i++) {
		int num = cmd[i].first;
		int dir = cmd[i].second;
		num--;
		vector<int> v(4);
		v[num] = dir;
		for (int i = num; i < 3; i++) {
			if (saw[i][2] == saw[i + 1][6]) v[i + 1] = 0;
			else v[i + 1] = -v[i];
		}
		for (int i = num; i > 0; i--) {
			if (saw[i][6] == saw[i - 1][2]) v[i - 1] = 0;
			else v[i - 1] = -v[i];
		}
		
		for (int i = 0; i < 4; i++) {
			rotate(i, v[i]);
		}
	}
}

void input() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 8; j++) {
			scanf("%1d", &saw[i][j]);
		}
	}

	cin >> K;
	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		cmd.push_back({ a,b });
	}
}

int cal() {
	int ans = 0;
	for (int i = 0; i < 4; i++) {
		if (saw[i][0] == 1) ans += pow(2, i);
	}
	return ans;
}
int main() {
	
	input();
	solve();
	cout << cal();
	return 0;
}