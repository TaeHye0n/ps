#include <string>
#include <vector>
using namespace std;


bool isProper(string s){
    vector<char> stk;
    for(char c : s){
        if(c == '(') stk.push_back(c);
        else {
            if(stk.empty()) return false;
             stk.pop_back();
        }
   }
    if(stk.empty()) return true;
    else return false;
}

string recur(string p){
     if(p.empty()) return p;
     string answer = "";
     string u = "";
     string v = "";
     int positive = 0;
     int negative = 0;
    
      for(int i = 0; i < p.size(); i++){
        if(p[i] == '(') positive++;
        else negative++;

        if(positive == negative ){
            u = p.substr(0,i+1);
            v = p.substr(i+1);
            break;
        }
    }
    if(isProper(u)) answer = u + recur(v);
    else{
        answer = "(" + recur(v) + ")";
        for(int i = 1; i < u.size()-1; i++){
            if(u[i] == '(') u[i] = ')';
            else u[i] = '(';
            answer += u[i];
          }
       }
    return answer;
}

string solution(string p) {
    return recur(p);
}