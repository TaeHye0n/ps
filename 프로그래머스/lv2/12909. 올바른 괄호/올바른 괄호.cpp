#include<string>
#include <iostream>
#include <vector>
using namespace std;

bool solution(string s)
{
    vector<char> v;
    bool answer = true;
    if(s[0] == ')' || s[s.size()-1] == '(') return false;
    for(int i = 0; i < s.size() ; i++){
        if(s[i] == '(') v.push_back(s[i]);
        else if(s[i] ==')' && v[v.size()-1] == '(' ) v.pop_back();
    }
    if(v.empty()) return true;
    else return false;

    return answer;
}