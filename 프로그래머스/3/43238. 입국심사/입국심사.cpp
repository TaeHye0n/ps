#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

ll solution(int n, vector<int> times) {
    ll answer = 0;
    sort(times.begin(), times.end());
    
    ll l = 1;
    ll r = (ll) times.back() * n / times.size();
    
    while (l <= r) {
        ll mid = (l + r) / 2;
        ll cnt = 0;
        
        for (int i = 0; i < times.size(); i++) {
            cnt += mid / times[i];
            if (cnt >= n) break;
        }
        
        if (cnt >= n) r = mid - 1;
        else {
            l = mid + 1;
        }
    }
    return l;
}