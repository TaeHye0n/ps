#include <string>
#include <vector>
#include <stack>
using namespace std;

vector<int> solution(vector<int> numbers) {
    int n = numbers.size();
    vector<int> answer(n);
    stack<int> stk;
        
    for (int i = 0; i < n; i++) {
        while (!stk.empty() && numbers[stk.top()] < numbers[i]) {
            answer[stk.top()] = numbers[i];    
            stk.pop();
        }
        stk.push(i);
    }
    
    while (!stk.empty()) {
        answer[stk.top()] = -1;
        stk.pop();
    }
    return answer;
}