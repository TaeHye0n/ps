#include <string>
#include <vector>
typedef long long ll;
using namespace std;

bool check(vector<int> diffs, vector<int> times, long long limit, int level) {
    ll sum = times[0];
    
    for (int i = 1; i < diffs.size(); i++) {
        int cur = diffs[i];
        if (level >= cur) {
            sum += times[i];
        } else {
            int t = cur - level;
            sum = sum + (times[i] + times[i - 1]) * t;
            sum += times[i];
        }
        if (sum > limit) return false;
    }
    return true;
}

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 1000001;
    
    int l = 1;
    int r = 100000;
    while (l <= r) {
       int mid = (l + r) / 2;
        if (check(diffs, times, limit, mid)) {
            answer = min(answer, mid);
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    return answer;
}