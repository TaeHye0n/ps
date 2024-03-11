#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    int st = 1;
    while (st <= n) {
        int sum = 0;
        for (int i = st; i <= n; i++) {
            sum += i;
            if (sum == n) answer++;
            if (sum > n) break;
        }
        st++;
    }
    return answer;
}