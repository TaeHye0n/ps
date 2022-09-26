#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;



int main() {
    
	int N = 0;
	cin >> N;

	vector<int> positive;
	vector<int> negative;
	int tmp = 0;
	int one = 0;
	int zero = 0;

	for (int i = 0; i < N; i++) {
		cin >> tmp;
		if (tmp == 1) one++;
		else if (tmp > 0) positive.push_back(tmp);
		else if (tmp < 0) negative.push_back(tmp);
		else zero++;
	}

	sort(positive.begin(), positive.end(), greater<int>());
	sort(negative.begin(), negative.end());
	if (positive.size() % 2 == 1) positive.push_back(1);
	if (negative.size() % 2 == 1) {
		if (zero > 0) negative.push_back(0);
		else negative.push_back(1);
	}

	int sum = 0;
	for (int i = 0; i < positive.size(); i += 2) {
		sum += positive[i] * positive[i + 1];
	}
	for (int i = 0; i < negative.size(); i += 2) {
		sum += negative[i] * negative[i + 1];
	}
	sum += one;
	cout << sum;

	
	
	return 0;
}
