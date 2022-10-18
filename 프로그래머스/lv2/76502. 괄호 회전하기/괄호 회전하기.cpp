#include <string>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

 int answer;

void isCorrect(string s){
    stack<int> stk;
    bool isPut = false;
    for(int i = 0; i < s.size(); i++){
        if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
            stk.push(s[i]);
            isPut = true;
        }
        else {
            if(s[i] == ')' && stk.top() == '(' ) stk.pop();
            if(s[i] == ']' && stk.top() == '[' ) stk.pop();
            if(s[i] == '}' && stk.top() == '{' ) stk.pop();
     }
    }
    if(stk.empty() && isPut == true) {
        answer++;
        return;  
    }
 
}

int solution(string s) {
    int i = 1;
    isCorrect(s);
    for(int i = 1; i < s.size(); i++){
        char tmp = s.front();
        s.erase(s.begin());
        s.push_back(tmp);
        isCorrect(s);
    }
        
    return answer;
}