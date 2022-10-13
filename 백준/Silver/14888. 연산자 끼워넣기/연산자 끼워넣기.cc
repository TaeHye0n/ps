#include<iostream>
#include<vector>
using namespace std;


int N;
int maxResult = -1000000001;
int minResult = 1000000001;
int num[11];
int oper[4];

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> oper[i];
	}
}

void solve(int result, int idx) {

	if (idx == N) {
		if (result > maxResult) maxResult = result;
		if (result < minResult) minResult = result;
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (oper[i] > 0) {
			oper[i]--;
			if (i == 0) solve(result + num[idx], idx + 1);
			else if (i == 1) solve(result - num[idx], idx + 1);
			else if (i == 2) solve(result * num[idx], idx + 1);
			else solve(result / num[idx], idx + 1);
			oper[i]++;
		}
	}

}

int main() {
	input();
	solve(num[0], 1);
	cout << maxResult << "\n";
	cout << minResult;
	return 0;
}