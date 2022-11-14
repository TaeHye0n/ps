#include <iostream>
#include <string>
using namespace std;


string polynomial;

void input() {
	cin >> polynomial;
}

string derivative(string s) {
	string temp = "";
	bool flag = false;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'x') {
			flag = true;
			break;
		}
		else temp += s[i];

	}
	if (!flag) return "0";
	return temp;
	
}
int solve() {
	int ans = 0;
	string first = "";
	string second = "";
	int idx = 0;
	for (int i = 0; i < polynomial.length(); i++) {
		if (polynomial[i] == 'x') {
			idx = i;
			break;
		}
	}
	if (idx == 0 && polynomial[idx] != 'x') return 0;

	first = polynomial.substr(0, idx+1);
	if (first == "-x") {
		first = "-1x";
	}
	else if (first[0] == 'x') {
		first = "1x";
	}
	second = polynomial.substr(idx+1);
	if (second == "-x") {
		second = "-1x";
	}
	else if (second == "+x") {
		second = "+1x";
	}
	first = derivative(first);
	second = derivative(second);

	ans = stoi(first) + stoi(second);
	return ans;
}

int main() {
	input();
	cout << solve();
	return 0;
}