#include <iostream>
#include <queue>

using namespace std;

int main() {
	int N = 0, K = 0;
	bool vi[100001] = { false, };
	int answer = 0;
	queue<pair<int, int>> q;

	cin >> N >> K;

	q.push({ N,0 });
	vi[N] = true;

	while (!q.empty()) {
		int locate = q.front().first;
		int times = q.front().second;
		q.pop();
		
		if (locate == K) {
			answer = times;
			break;
		}

		for (int w = 0; w < 3; w++) {
			if (w == 0 && locate - 1 >= 0 && vi[locate - 1] == 0 ) {
				q.push({ locate - 1, times + 1 });
				vi[locate - 1] = true;
			}
			else if (w == 1 && locate + 1 < 100001 && vi[locate + 1] == 0 ) {
				q.push({ locate + 1, times + 1 });
				vi[locate + 1] = true;
			}
			else if (w == 2 && locate * 2 < 100001 && vi[locate * 2] == 0 ) {
				q.push({ locate * 2, times + 1 });
				vi[locate * 2] = true;
			}

		}
	}

	cout << answer;
	return 0;
}