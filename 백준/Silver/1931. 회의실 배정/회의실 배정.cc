#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) return a.first < b.first;
	else return a.second < b.second;
}

int main() {
    
	int N = 0;
	int begin, end = 0;
	cin >> N;
	vector<pair<int, int>> schedule;

	for (int i = 0; i < N; i++) {
		cin >> begin >> end;
		schedule.push_back({ begin,end });
	}
	sort(schedule.begin(), schedule.end(), cmp);

	int time = schedule[0].second;
	int cnt = 1;

	for (int i = 1; i < N; i++) {
		if (schedule[i].first >= time) {
			cnt++;
			time = schedule[i].second;
		}
	}
	cout << cnt;
	
	return 0;
}
