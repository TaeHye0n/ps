#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;



int main() {
    
	string s = "";
	cin >> s;

	int zeroArea = 0;
	int oneArea = 0;

	for (int i = 0; i < s.length(); i++) {
		if (s[i] != s[i + 1]) {
			if (s[i] == '0') zeroArea++;
			else oneArea++;
		}
	}
	cout << min(zeroArea, oneArea);
	
	return 0;
}
