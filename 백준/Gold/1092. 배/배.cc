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
	while (cnt < M) {
		answer++;
		int idx = N - 1;
		for (int i = M - 1; i >= 0; i--) {
			if (isCarried[i]) continue;
			if (idx == -1) break;
			if (boxes[i] <= crane[idx]) {
				idx--;
				cnt++;
				isCarried[i] = true;
			}
		}
	}
	cout << answer;
	return 0;
}