#include <string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string str)
{
    stack<char> s;
    
    for (auto c : str) {
        if (c == '(') s.push(c);
        else if (c == ')' && !s.empty()) s.pop();
        else return false;
    }
    
    return s.size() == 0 ? true : false;
}