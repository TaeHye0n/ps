#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int N;
int inputTeam;
string inputTime;
int score[3], winningTime[3];
int currTime, prevTime;
int winningTeam;

int changeToSeconds(string s) {
	string mins = s.substr(0, 2);
	string secs = s.substr(3);

	return stoi(mins) * 60 + stoi(secs);
}
int main() {
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	while (N--) {
		cin >> inputTeam >> inputTime;
		score[inputTeam]++;
		currTime = changeToSeconds(inputTime);

		winningTime[winningTeam] += currTime - prevTime;

		prevTime = currTime;

		if (score[1] > score[2]) winningTeam = 1;
		else if (score[2] > score[1]) winningTeam = 2;
		else if(score[1] == score[2]) winningTeam = 0;
	}
	winningTime[winningTeam] += (48 * 60) - prevTime;

	printf("%02d:%02d\n", winningTime[1] / 60, winningTime[1] % 60);
	printf("%02d:%02d", winningTime[2] / 60, winningTime[2] % 60);

	return 0;
}