#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int check = -1;
    string tmp = "";
    
    for(auto &c : s){
        c = tolower(c);
    }
    
    for(int i = 0; i < s.size()-1; i++){
       tmp += s[i];
        if(s[i] == ' ' && s[i+1] != ' '){
            if(tmp[0] >= 'a' && tmp[0] <= 'z') tmp[0] = toupper(tmp[0]);
            answer += tmp;
            tmp = "";
            check = i;
        }
    }
    
    for(int j = check+1 ; j < s.size(); j++){
        if(s[check+1] >= 'a' && s[check+1] <= 'z') s[check+1] = toupper(s[j]);
        answer += s[j];
    }
    return answer;
}