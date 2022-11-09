#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    for(string s : babbling){
        bool flag = true;
        int check = 0;
        for(int idx = 0; idx < s.length(); ){
            if(check != 1 && s.substr(idx,3) == "aya") idx += 3, check = 1;
            else if(check != 2 && s.substr(idx,2) == "ye") idx +=2, check = 2;
            else if(check != 3 && s.substr(idx,3) == "woo") idx +=3, check =3;
            else if(check != 4 && s.substr(idx,2) == "ma") idx +=2, check =4;
            else{
                flag = false;
                break;
            }
        }
        if(flag) {
            answer++;
            // cout << s << "\n";
        }
    }
    return answer;
}