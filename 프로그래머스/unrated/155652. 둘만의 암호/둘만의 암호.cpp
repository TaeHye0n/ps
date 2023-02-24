#include <string>
#include <vector>
#include <set>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    
    set<int> ss;
    int saveidx = index;
    
    for(int i = 0; i < skip.length(); i++){
        int temp = skip[i];
        ss.insert(temp);
    }
    
    for(int i = 0; i < s.length(); i++){
        int temp = s[i];
        
        while(index--){
            temp += 1;
            if(temp == 'z'+1){
                temp = 'a';
            }
            if(ss.find(temp) != ss.end()){
                index += 1;
            }
        }
        char c = temp;
        answer += c;
        index = saveidx;
    }
    return answer;
}