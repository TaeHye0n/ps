#include <string>
#include <vector>

using namespace std;
vector<int> numbers;
int answer;
void dfs(int idx, int cur, int target) {
    if (idx == numbers.size()) {
        if (cur == target) {
            answer++;
        }
        return;
    }
    
    dfs(idx + 1, cur + numbers[idx], target);
    dfs(idx + 1, cur - numbers[idx], target);
}

int solution(vector<int> number, int target) {
    numbers = number;
    dfs(0, 0, target);
    return answer;
}