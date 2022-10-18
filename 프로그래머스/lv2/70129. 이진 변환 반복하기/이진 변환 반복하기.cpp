#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int zero_cnt = 0;
    int trial_cnt = 0;
    
    
    while(s != "1"){
        string tmp = "";
        
       for(char c : s){
           if(c == '0') zero_cnt++;
           else tmp += '1';
       }    
        
        int len = tmp.size();
        s = "";
        while(len > 0){
            s += to_string(len % 2);
            len /= 2;
        }
        trial_cnt++;
    }
    answer = {trial_cnt, zero_cnt};
    return answer;
}