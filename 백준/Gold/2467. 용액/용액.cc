#include <iostream>

#define MAX 100001
using namespace std;

int N;
int solution[MAX];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> solution[i];
	}
	pair<int, int> answer;
	int st = 0, ed = N - 1;
	long long sum = abs(solution[0] + solution[ed]);
	answer = { solution[0], solution[ed] };
	while (ed > st) {
		long long temp = solution[ed] + solution[st];
		if (temp == 0) {
			answer = { solution[st], solution[ed] };
			break;
		}
		if (abs(temp) < sum) {
			sum = abs(temp);
			answer = { solution[st], solution[ed] };
		}

		if (temp > 0) {
			ed--;
		}
		else st++;
	}
	cout << answer.first << " " << answer.second;
	return 0;
}