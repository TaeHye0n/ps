#include <iostream>
#include <algorithm>

using namespace std;

int N; // 토핑의 종류의 수
int A, B; //도우 가격 A, 토핑 가격 B
int C; // 도우 열량
int arr[101]; // 토핑의 열량

int price, cal;

void input() {
	cin >> N;
	cin >> A >> B;
	cin >> C;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
}

void solve() {
	price = A;
	cal = C;
	sort(arr, arr + N, greater<int>());
	int maxCalPerOne = C / A;

	for (int i = 0; i < N; i++) {
		int temp = price + B;
		int temp2 = cal + arr[i];
		int temp3 = temp2 / temp;
		if (temp3 >= maxCalPerOne) {
			price = temp;
			cal = temp2;
			maxCalPerOne = temp3;
		}
		else break;
	}

	cout << maxCalPerOne;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	input();
	solve();
	return 0;
}