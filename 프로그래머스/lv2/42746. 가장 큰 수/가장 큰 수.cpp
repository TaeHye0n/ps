#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool cmp(string a, string b){
    return a + b > b + a;
}
string solution(vector<int> numbers) {
    string answer = "";
    vector<string> s;
    
    for(auto num : numbers){
        s.push_back(to_string(num));
    }
    sort(s.begin(), s.end(), cmp);
    if(s.front() == "0") return "0";
    
    
    for(auto ss: s){
        answer += ss;
    }
    return answer;
}