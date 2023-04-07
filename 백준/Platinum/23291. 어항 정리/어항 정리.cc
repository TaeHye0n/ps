#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int INF = 10001;
const int dy[2] = { -1,0 };
const int dx[2] = { 0,1 };
int N; // 어항의 수
int K; // 물고기가 가장 많이 들어있는 어항과 가장 적게 들어있는 어항의 물고기 수 차이가 K 이하가 돼야함
deque<int> bowl[101];
void input() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		int temp;
		cin >> temp;
		bowl[0].push_back(temp);
	}
}
void addFish() {
	int minFishCnt = INF;
	vector<int> idxVector;
	for (int i = 0; i < bowl[0].size(); i++) {
		if (minFishCnt > bowl[0][i]) {
			minFishCnt = bowl[0][i];
			idxVector.clear();
			idxVector.push_back(i);
		}
		else if (minFishCnt == bowl[0][i]) idxVector.push_back(i);
	}

	for (int idx : idxVector) {
		bowl[0][idx]++;
	}
}
int stackBowl() {
	int height = 1;
	int width = 1;
	int whichPlus = 1;
	while (1) {
		if (height > bowl[0].size() - width) break;

		int width2 = width;
		for (int i = 0; i < width; i++) {
			int idx = 0;
			for (int j = 0; j < height; j++) {
				bowl[width2].push_back(bowl[idx][i]);
				idx++;
			}
			width2--;
		}

		for (int i = 0; i < height; i++) {
			for (int j = 0; j < width; j++) {
				bowl[i].pop_front();
			}
		}
		if (whichPlus % 2 == 1)  height++;
		else width++;
		whichPlus++;
	}
	return height;
}
void changeFishCnt(int height) {
	deque<int> temp[101];
	for (int i = 0; i < height; i++) {
		temp[i] = bowl[i];
	}
	for (int i = height - 1; i >= 0; i--) {
		for (int j = 0; j < bowl[i].size(); j++) {
			for (int w = 0; w < 2; w++) {
				int ny = i + dy[w];
				int nx = j + dx[w];
				if (ny < 0 || nx >= bowl[i].size()) continue;
				int d = abs(bowl[ny][nx] - bowl[i][j]) / 5;
				if (d > 0) {
					if (bowl[i][j] > bowl[ny][nx]) {
						temp[i][j] -= d;
						temp[ny][nx] += d;
					}
					else {
						temp[i][j] += d;
						temp[ny][nx] -= d;
					}
				}
			}
		}
	}
	for (int i = 0; i < height; i++) {
		bowl[i] = temp[i];
	}
}
void lineupBowl(int height) {
	int size = bowl[0].size();
	int width = bowl[height - 1].size();
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			bowl[0].push_back(bowl[j][i]);
		}
	}
	for (int i = 1; i < height; i++) {
		bowl[i].clear();
	}
	for (int i = width; i < size; i++) {
		bowl[0].push_back(bowl[0][i]);
	}
	for (int i = 0; i < size; i++) {
		bowl[0].pop_front();
	}
}
void restackBowl() {
	int n = bowl[0].size();
	for (int i = 0; i < n / 2; i++) {
		bowl[1].push_front(bowl[0][i]);
	}
	for (int i = 0; i < n / 2; i++) {
		bowl[0].pop_front();
	}
	for (int i = 0; i < n / 4; i++) {
		bowl[2].push_front(bowl[1][i]);
		bowl[3].push_front(bowl[0][i]);
	}
	for (int i = 0; i < n / 4; i++) {
		bowl[1].pop_front();
		bowl[0].pop_front();
	}
}
void solve() {
	// 1.먼저, 물고기의 수가 가장 적은 어항에 물고기를 한 마리 넣는다. 만약, 그러한 어항이 여러개라면 물고기의 수가 최소인 어항 모두에 한 마리씩 넣는다
	addFish();
	// 2.이제 어항을 쌓는다. 먼저, 가장 왼쪽에 있는 어항을 그 어항의 오른쪽에 있는 어항의 위에 올려 놓아
	int height = stackBowl();
	// 3.어항에 있는 물고기의 수를 조절한다.
	changeFishCnt(height);
	// 4.이제 다시 어항을 바닥에 일렬로 놓아야 한다. 
	lineupBowl(height);
	// 5.다시 공중 부양 작업을 해야 한다. 
	restackBowl();
	// 6.여기서 다시 위에서 한 물고기 조절 작업을 수행하고,
	changeFishCnt(4);
	// 7.바닥에 일렬로 놓는 작업을 수행한다. 
	lineupBowl(4);

}
bool check() {
	int maxFishCnt = -INF;
	int minFishCnt = INF;
	for (int i = 0; i < bowl[0].size(); i++) {
		if (bowl[0][i] > maxFishCnt) maxFishCnt = bowl[0][i];
		if (bowl[0][i] < minFishCnt) minFishCnt = bowl[0][i];
	}
	if (maxFishCnt - minFishCnt <= K) return true;
	return false;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	input();
	int answer = 0;
	while (!check()) {
		solve();
		answer++;
	}
	cout << answer << "\n";
	return 0;
}