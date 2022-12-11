#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    map<char,int> check;
    
    for(int i = 0; i < s.length(); i++){
        if(check.find(s[i]) == check.end()){
            answer.push_back(-1);
            check.insert({s[i],i});
        }
        else{
            answer.push_back(i-check[s[i]]);
            check[s[i]] = i;
        }
    }
    return answer;
}