#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

string solution(string s) {
    string answer = "";
    vector<int> v;
    
    stringstream ss;
    ss.str(s);
    int num;
    while(ss >> num) v.push_back(num);
    
    sort(v.begin(), v.end());
    answer += to_string(v.at(0));
    answer += " ";
    answer += to_string(v.back());
    return answer;
}