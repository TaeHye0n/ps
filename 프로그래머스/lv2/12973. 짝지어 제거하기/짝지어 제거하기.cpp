#include <iostream>
#include <string>
#include <stack>

using namespace std;
stack<char> t;
int solution(string s)
{
    int answer = -1;
    
    for(int i = 0; i < s.size(); i++){
        if(t.empty() || t.top() != s[i]) t.push(s[i]);
        else if(t.top() == s[i]) t.pop();
    }
    if(t.empty()) answer = 1;
    else answer = 0;
   

    return answer;
}