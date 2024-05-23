#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define FAST_IO ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
#define endl "\n"
#define nano 10000000

using namespace std;
typedef long long ll;


int main() {
    FAST_IO;

    int x = 0;
    int n = 0;
    while (cin >> x >> n) {
        vector<int> v;
        for (int i = 0; i < n; i++) {
            int val = 0;
            cin >> val;
            v.push_back(val);
        }
        sort(v.begin(), v.end());

        x *= nano;

        pair<int, int> answer = {0, 0};

        int l = 0, r = n - 1;
        int sum = 0;

        while (l < r) {
            sum = v[r] + v[l];

            if (sum > x) r--;
            else if (sum < x) l++;
            else {
                answer = {v[l], v[r]};
                break;
            }
        }

        if (answer.first == 0) {
            cout << "danger" << endl;
        } else {
            cout << "yes " << answer.first << " " << answer.second << endl;
        }
    }

    return 0;
}

