#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int T, N;
vector<int> stock(1000001, 0);

long long solve() {
    int max = stock.back();
    long long ans = 0;
    for (int i = stock.size() - 2; i >= 0; i--) {
        if (stock[i] > max) max = stock[i];
        else ans += max - stock[i];
    }
    return ans;
}

int main() {
    cin >> T;
    for (int tc = 1; tc <= T; tc++) {
        stock.clear();
        cin >> N;
        int temp = 0;
        for (int i = 0; i < N; i++) {
            cin >> temp;
            stock.push_back(temp);
        }
        cout << solve() << "\n";
    }
    return 0;
}