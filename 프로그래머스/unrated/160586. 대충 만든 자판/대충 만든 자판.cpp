#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> keymap, vector<string> targets) {
    vector<int> answer;
    
    map<char,int> m;
    for(int i = 0; i < keymap.size(); i++){
        for(int j = 0; j < keymap[i].length(); j++){
            if(m.find(keymap[i][j]) != m.end()){
                if(m[keymap[i][j]] > j+1){
                    m[keymap[i][j]] = j+1;
                }
            }
            else m.insert({keymap[i][j], j+1});
        }
    }
    
    for(int i = 0; i < targets.size(); i++){
        bool flag = false;
        int temp = 0;
        for(int j = 0; j < targets[i].length(); j++){
            if(m.find(targets[i][j]) == m.end()){
                answer.push_back(-1);
                flag = true;
                break;
            }
            else{
                temp += m[targets[i][j]];
            }
        }
        if(!flag) answer.push_back(temp);
    }
    
    return answer;
}