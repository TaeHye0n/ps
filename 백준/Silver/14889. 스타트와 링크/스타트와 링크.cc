#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool vi[21];
int status[21][21];
int N;
int answer = 999999999;

void recur(int cnt, int cur) {
	if (cnt == N / 2) {
		int start_team = 0;
		int link_team = 0;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (vi[i] == false && vi[j] == false) link_team += status[i][j];
				if (vi[i] == true && vi[j] == true) start_team += status[i][j];
			}
		}
		
		answer = min(answer, abs(link_team - start_team));
		
		return;
	}
	for (int i = cur; i < N-1; i++) {
		vi[i] = true;
		recur(cnt + 1, i + 1);
		vi[i] = false;
	}
	
	
}

int main() {
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> status[i][j];
		}
	}
	recur(0, 0);
	cout << answer;
	return 0;
}