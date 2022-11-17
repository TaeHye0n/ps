#include <iostream>
#include <vector>

using namespace std;

const int dy[4] = { 1,0,-1,0 };
const int dx[4] = { 0,1,0,-1 };

int A, B;
int N, M;

int map[101][101];


struct robot {
	int y, x, dir;
};

vector<robot> v(101);

int selectDir(char c) {
	if (c == 'N') return 0;
	else if (c == 'E') return 1;
	else if (c == 'S') return 2;
	return 3;
}

int changeDir(int dir, char c) {
	if (c == 'R') return (dir + 1) % 4;
	return (dir + 3) % 4;
}

void solve() {
	cin >> A >> B;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int a, b;
		char c;
		cin >> a >> b >> c;
		v[i] = { b,a,selectDir(c) };
	}
	
	for (int j = 0; j < M; j++) {
		int idx, cnt;
		char command;
		cin >> idx >> command >> cnt;


		while (cnt--) {
			if (command == 'F') {
				int ny = v[idx].y + dy[v[idx].dir];
				int nx = v[idx].x + dx[v[idx].dir];

				if (ny < 1 || nx < 1 || ny > B || nx > A) {
					cout << "Robot " << idx << " crashes into the wall";
					return;
				}

				for (int i = 0; i < v.size(); i++) {
					if (i != idx && ny == v[i].y && nx == v[i].x) {
						cout << "Robot " << idx << " crashes into robot " << i;
						return;
					}
				}
				v[idx].y = ny;
				v[idx].x = nx;
			}
			else {
				v[idx].dir = changeDir(v[idx].dir, command);
			}
		}
	}

	cout << "OK";
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	solve();
	return 0;
}