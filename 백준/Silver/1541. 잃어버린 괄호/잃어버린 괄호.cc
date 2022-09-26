#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;



int main() {
    
	string s = "";
	cin >> s;

	int sum = 0;
	string num = "";
	bool flag = false;
	for (int i = 0; i <= s.length(); i++) {
		if (s[i] == '+' || s[i] == '-' || i == s.length()) {
			if (flag == true) {
				sum -= stoi(num);
				num = "";
			}
			else {
				sum += stoi(num);
				num = "";
			}
		}
		else {
			num += s[i];
		}
		if (s[i] == '-') {
			flag = true;
		}
	}
	cout << sum;
	return 0;
}
