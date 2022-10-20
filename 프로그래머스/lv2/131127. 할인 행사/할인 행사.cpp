#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    map<string, int> m;
    map<string, int> m2;
    
    for(int i = 0 ; i < want.size(); i++){
        m[want[i]] = number[i];
    }
    
    int size = discount.size();
    int idx = 0 ;
    while(1){
        if(idx + 10 > size) break;
        for(int i = idx; i < idx+10; i++){
             m2[discount[i]]++;
        }
        bool flag = true;
        for(int i = 0; i < want.size(); i++){
            if(m[want[i]] != m2[want[i]]){
                flag = false;
            }
        }
        if(flag) answer++;
        m2.clear();
        idx++;
    }
    return answer;
}