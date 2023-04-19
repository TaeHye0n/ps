#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool isCarried[10001];
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
		
	int N = 0; // 크레인의 수
	cin >> N;
	int crane[51] = { 0, };
	for (int i = 0; i < N; i++) {
		cin >> crane[i];
	}
	int M = 0; // 박스의 수
	cin >> M;
	int boxes[10001] = { 0, };
	for (int i = 0; i < M; i++) {
		cin >> boxes[i];
	}
	
	sort(crane, crane + N);
	sort(boxes, boxes + M);
	int answer = 0;
	if (crane[N-1] < boxes[M-1]) {
		cout << -1;
		return 0;
	}

	int cnt = 0;
	int realcnt = 0;
	int idx = M-1;
	while (1) {
		bool flag = false;
		for (int i = N - 1; i >= 0; i--) {
			for (int j = idx; j >= 0; j--) {
				if (isCarried[j]) continue;
				if (crane[i] >= boxes[j]) {
					cnt++;
					realcnt++;
					isCarried[j] = true;
					idx = j - 1;
					break;
				}
				else flag = true;
			}
			if (cnt == N || (flag == true && i == 0)) {
				answer++;
				cnt = 0;
				idx = M - 1;
				break;
			}
		}
		if (realcnt == M) {
			if (cnt != N && cnt != 0) answer++;
			break;
		}
	}
	cout << answer;
	return 0;
}