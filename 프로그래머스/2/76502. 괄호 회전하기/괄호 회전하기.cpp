#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    int n = s.size();
    string temp = "";

    int cnt = 0;
    while(1) {
        bool flag = false;
        if (cnt == n) break;
        cnt++;
        string temp = "";
        temp = s.front();
        temp = s.substr(1, n) + temp;
        stack<char> stk;
        s = temp;
        
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (c == '(' || c == '{' || c == '[') stk.push(c);
            if (stk.empty()) {
                flag = true;
                break;
            } 
            
            if (stk.top() == '(' && c == ')') stk.pop();
            else if (stk.top() == '{' && c == '}') stk.pop();
            else if (stk.top() == '[' && c == ']') stk.pop();
        }
        
        if (!flag && stk.empty()) answer++;

    }
    return answer;
}