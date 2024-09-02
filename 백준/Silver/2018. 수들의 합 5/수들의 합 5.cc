#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <algorithm>
#include <climits>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
#define Y first
#define X second
using namespace std;
typedef long long ll;

int N;

int main() {
    FAST_IO;
    
    cin >> N;
    int ans = 1;

    int l = 1, r = 1;
    int sum = 0;

    while (l <= r) {
        if (r > N) break;
        if (sum < N) sum += r++;
        else {
            if (sum == N) ans++;
            sum -= l++;
        }
    }

    cout << ans;

    return 0;
}