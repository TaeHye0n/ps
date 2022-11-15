#include <iostream>

using namespace std;

int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0,-1 };

int changeDir(int dir, char c) {
	if (c == 'R') return (dir + 1) % 4;
	else {
		if (dir == 0) return 3;
		else if (dir == 1) return 0;
		else if (dir == 2) return 1;
		else return 2;
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		string command = "";
		cin >> command;
		
		int currDir = 0;
		int y = 0;
		int x = 0;
		int minX = 0, minY = 0, maxX = 0, maxY = 0;
		for (int i = 0; i < command.length(); i++) {
			if (command[i] == 'F') {
				y +=  dy[currDir];
				x +=  dx[currDir];
			}
			else if (command[i] == 'B') {
				int tempDir = (currDir + 2) % 4;
				y +=  dy[tempDir];
				x +=  dx[tempDir];
			}
			else {
				currDir = changeDir(currDir, command[i]);
			}

			if (maxX < x) maxX = x;
			if (maxY < y) maxY = y;
			if (minX > x) minX = x;
			if (minY > y) minY = y;
		}
		
		cout << ((maxX - minX) * (maxY - minY)) << "\n";

		
	}
	return 0;
}