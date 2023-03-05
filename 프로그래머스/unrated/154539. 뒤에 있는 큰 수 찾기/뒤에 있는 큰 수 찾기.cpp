#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size());
    stack<int> s;
    
    for(int i = 0; i < numbers.size(); i++){
        while(!s.empty() && numbers[s.top()] < numbers[i]){
            answer[s.top()] = numbers[i];
            s.pop();
        }
        s.push(i);
    }
    
    while(!s.empty()){
        answer[s.top()] = -1;
        s.pop();
    }
    return answer;
}