#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

int T;
vector<string> recored;
vector<string> sound;
void solve();

void input() {
	cin >> T;
	cin.ignore();
	for (int tc = 1; tc <= T; tc++) {
		recored.clear();
		sound.clear();
		string input = "";
		getline(cin, input);
		stringstream ss;
		ss.str(input);
		string temp = "";
		while (ss >> temp) recored.push_back(temp);
		while (1) {
			string temp = "";
			string a, b, c = "";
			getline(cin, temp);
			stringstream ss2;
			ss2.str(temp);
			ss2 >> a >> b >> c;
			if (a == "what") break;
			sound.push_back(c);
		}
		solve();
	}
}

void solve() {
	for (int i = 0; i < recored.size(); i++) {
		for (int j = 0; j < sound.size(); j++) {
			if (recored[i] == sound[j]) recored[i] = " ";
		}
	}
	for (int i = 0; i < recored.size(); i++) {
		if (recored[i] != " ") cout << recored[i] << " ";
	}
	cout << "\n";
}

int main() {
	input();

	
	return 0;
}