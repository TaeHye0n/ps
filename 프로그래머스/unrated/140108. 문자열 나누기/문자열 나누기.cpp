#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    
    bool flag = true;
    vector<int> v(2);
    char temp = ' ';
    
    for(int i = 0; i < s.length(); i++){
        if(flag){
            v.clear();
            flag = false;
            temp = s[i];
        }
        
        if(temp == s[i]) v[0]++;
        else v[1]++;
        
        if(i == s.length()-1){
            answer++;
            break;
        }
        if(v[0]==v[1]){
            answer++;
            flag = true;
        }
    }
    return answer;
}