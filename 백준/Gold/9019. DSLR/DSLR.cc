#include<iostream>
#include<queue>
#include<string>
#include<cstring>
using namespace std;


int T, A, B;
string answer;
bool vi[10000];


void solve() {
	queue<pair<int, string>> q;
	q.push({ A, "" });
	vi[A] = true;

	while (!q.empty()) {
		int num = q.front().first;
		string DSLR = q.front().second;
		
		q.pop();

		
		if (num == B) {
			answer = DSLR;
			break;
		}

		for (int w = 0; w < 4; w++) {
			if (w == 0 && vi[(2 * num) % 10000] == false) {
				q.push({ (2 * num) % 10000,DSLR + "D" });
				vi[(2 * num) % 10000] = true;
			}

			int z = num - 1 < 0 ? 9999 : num - 1;
			if (w == 1 &&  vi[z] == false) {
				q.push({z , DSLR + "S" });
				vi[z] = true;
			}

			int x = (num % 1000) * 10 + (num / 1000);
			if (w == 2 && vi[x] == false) {
				q.push({ x, DSLR + "L" });
				vi[x] = true;
			}
			int y = num / 10 + (num % 10) * 1000;
			if (w == 3 && vi[y] == false) {
				q.push({ y, DSLR + "R" });
				vi[y] = true;
			}
            
		}
	}
}

int main() {

	cin >> T;

	while (T--) {
		cin >> A >> B;
		memset(vi, false, sizeof(vi));
		solve();
		cout << answer << endl;
	}

	return 0;
}