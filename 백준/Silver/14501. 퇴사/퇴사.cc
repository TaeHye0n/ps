#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int N;
int myTime[16];
int pay[16];
int res[16];

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> myTime[i] >> pay[i];
	}
}

void DP() {
	int deadline = 0;
	for (int i = N; i > 0; i--) {
		deadline = i + myTime[i];
		if (deadline > N + 1) {
			res[i] = res[i + 1];
		}
		else {
			res[i] = max(res[i + 1], res[deadline] + pay[i]);
		}
	}
}

int main() {

	input();
	DP();
	cout << res[1];
	return 0;
}