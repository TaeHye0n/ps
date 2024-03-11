#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    int n = people.size();
    int st = 0;
    int ed = n - 1;
    sort(people.begin(), people.end());
    
    while (st <= ed) {
        int sum = people[st] + people[ed--];
        if (sum <= limit) st++;
        answer++;
    }
    return answer;
}