#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>
#include <queue>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
#define Y first
#define X second

#define MAX 51
using namespace std;
typedef long long ll;

const int dy[8] = { -1, -1, 0, 1, 1, 1, 0, -1 };
const int dx[8] = { 0, 1, 1 ,1 ,0, -1, -1, -1 };

struct fireball {
	int r;
	int c;
	int m;
	int d;
	int s;
};

vector<fireball> board[MAX][MAX];
vector<fireball> fireballs;
int N, M, K; // 격자 크기 N, 파이어볼 M개, K번 명령
int main() {
	FAST_IO;

	cin >> N >> M >> K;

	queue<fireball> q;

	for (int i = 0; i < M; i++) {
		int r, c, m, s, d;
		cin >> r >> c >> m >> s >> d;
		fireballs.push_back({ r, c, m, d, s });
	}

	while (K--) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				board[i][j].clear();
			}
		}

		vector<fireball> temp;
		// 1. 이동
		for (auto &f : fireballs) {
			int speed = f.s % N;

			// 격자 외곽들이 연결 되어있음
			int ny = (f.r + dy[f.d] * speed - 1 + N) % N + 1;  
			int nx = (f.c + dx[f.d] * speed - 1 + N) % N + 1; 
			f.r = ny;
			f.c = nx;
			board[ny][nx].push_back(f);
		}

		// 2. 2개 이상 파이어볼 있는 칸 로직
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (board[i][j].size() == 1) {
					temp.push_back(board[i][j][0]);
				} 
				else if (board[i][j].size() >= 2) {
					bool all_even = true, all_odd = true;
					int mass_sum = 0;
					int speed_sum = 0;
					int cnt = board[i][j].size();

					for (auto& f : board[i][j]) {
						mass_sum += f.m;
						speed_sum += f.s;

						if (f.d % 2 == 0) all_odd = false;
						else all_even = false;
					}

					int new_mass = mass_sum / 5;
					int new_speed = speed_sum / cnt;

					if (new_mass == 0) continue;

					if (all_even || all_odd) {
						for (int w = 0; w < 8; w += 2) {
							temp.push_back({ i, j, new_mass, w, new_speed });
						}
					}
					else {
						for (int w = 1; w < 8; w += 2) {
							temp.push_back({ i, j, new_mass, w, new_speed });
						}
					}
				}
			}
		}
		fireballs = temp;
	}

	int ans = 0;
	for (auto& f : fireballs) {
		ans += f.m;
	}
	
	cout << ans;
	return 0;
}