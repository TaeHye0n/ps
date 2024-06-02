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


ll x, y; // x <= 1,000,000,000, y <= x

int main() {
    FAST_IO;
    
    cin >> x >> y;

    ll z = (y * 100) / x;

    if (z >= 99) {
        cout << -1;
        return 0;
    }

    ll l = 0; ll r = 1000000000;

    while (l <= r) {
        ll mid = (l + r) / 2;

        ll prob = ((y + mid) * 100) / (x + mid);

        if (prob > z) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    cout << l;

    return 0;
}