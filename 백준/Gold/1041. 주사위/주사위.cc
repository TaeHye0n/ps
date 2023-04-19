#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	
	long long N = 0;
	cin >> N;
	long long answer = 0;
	int dice[6] = { 0, };
	int maxNum = 0;
	long long sum = 0;
	for (int i = 0; i < 6; i++) {
		cin >> dice[i];
		sum += dice[i];
		maxNum = max(maxNum, dice[i]);
	}

	if (N == 1) {
		cout << sum - maxNum;
		return 0;
	}
	dice[0] = min(dice[0], dice[5]);
	dice[1] = min(dice[1], dice[4]);
	dice[2] = min(dice[2], dice[3]);

	sort(dice, dice + 3);
	
	long long min[3] = { 0, };
	min[0] = dice[0] + dice[1] + dice[2];
	min[1] = dice[0] + dice[1];
	min[2] = dice[0];
	answer += min[2]*((N - 1) * (N - 2) * 4 + (N - 2) * (N - 2));
	answer += min[1] * ((N - 1) + (N - 2)) * 4;
	answer += min[0] * 4;

	cout << answer;
	return 0;
}