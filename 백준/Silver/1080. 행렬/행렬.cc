#include <iostream>
#include <cstdio>

#define MAX 51
using namespace std;

int N, M;
int st[MAX][MAX];
int ed[MAX][MAX];
int ans;

void input() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &st[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &ed[i][j]);
		}
	}
}

int solve() {
	for (int i = 0; i < N - 2; i++) {
		for (int j = 0; j < M - 2; j++) {
			if (st[i][j] != ed[i][j]) {
				for (int a = i; a <= i + 2; a++) {
					for (int b = j; b <= j + 2; b++) {
						st[a][b] = 1 - st[a][b];
					}
				}
				ans += 1;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (st[i][j] != ed[i][j]) {
				return -1;
			}
		}
	}
	return ans;
}

int main() {
	input();
	cout << solve();
	return 0;
}