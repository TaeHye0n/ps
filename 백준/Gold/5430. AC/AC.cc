#include <iostream>
#include <queue>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int T;
	cin >> T;
	while (T--) {
		string command = "";
		string nums = "";
		int n = 0;
		deque<string> dq;

		cin >> command;
		cin >> n;
		cin >> nums;
		string temp = "";
		for (int i = 1; i < nums.length(); i++) {
			if (nums[i] == ',' || nums[i] == ']') {
				if (temp == "") continue;
				dq.push_back(temp);
				temp = "";
			}
			else temp += nums[i];
		}
		
		bool isReversed = false;
		bool isError = false;
		for (int i = 0; i < command.length(); i++) {
			if (command[i] == 'R') isReversed = !isReversed;
			else {
				if (dq.empty()) {
					isError = true;
					break;
				}
				else {
					if (!isReversed) dq.pop_front();
					else dq.pop_back();
				}
			}
		}

		if (isError) cout << "error" << "\n";
		else {
			if (!dq.empty()) {
				cout << "[";
				if (!isReversed) {
					cout << dq.front();
					dq.pop_front();
					while (!dq.empty()) {
						cout << "," << dq.front();
						dq.pop_front();
					}
				}
				else {
					cout << dq.back();
					dq.pop_back();
					while (!dq.empty()) {
						cout << "," << dq.back();
						dq.pop_back();
					}
				}
				cout << "]\n";
			}
			else {
				cout << "[]\n";
			}
		}
	}
	return 0;
}