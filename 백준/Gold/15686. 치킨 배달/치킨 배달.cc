#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int N, M, chickenSize, answer;
int map[51][51];
bool selected[14];
vector<pair<int, int>> house, chicken, temp;

void input() {
	answer = 1000000000;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) house.push_back({ i,j });
			if (map[i][j] == 2) chicken.push_back({ i,j });
		}
	}
	chickenSize = chicken.size();
}

void calculatedistance() {

	int sum = 0;
	for (int i = 0; i < house.size(); i++) {
		int x = house[i].first;
		int y = house[i].second;
		int distance = 1000000000;
		for (int j = 0; j < temp.size(); j++) {
			int x2 = temp[j].first;
			int y2 = temp[j].second;
			int distance2 = abs(x2 - x) + abs(y2 - y);

			distance = min(distance, distance2);
		}
		sum += distance;
	}

	answer = min(sum, answer);
}

void dfs(int idx, int cnt) {
	if (cnt == M)
	{
		calculatedistance();
		return;
	}
	for (int i = idx; i < chickenSize; i++) {
		temp.push_back(chicken[i]);
		dfs(i+1, cnt + 1);	
		temp.pop_back();
	}

}
int main() {
	input();
	dfs(0, 0);

	cout << answer;
	return 0;
}