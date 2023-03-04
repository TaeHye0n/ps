#include <string>
#include <vector>
using namespace std;

int solution(string t, string p) {
    int answer = 0;
    
    int size = p.length();
    vector<long long> comb;
    
   
    for(int i = 0; i < t.length(); i++){
        string temp = "";
        for(int j = i; (j < size + i && j < t.length()); j++){
            temp += t[j];
        }
        
        if(temp.length() != size) continue;
        comb.push_back(stol(temp));
    }
    
    for(auto num : comb){
        if(num <= stol(p)) answer++;      
    }
    
    return answer;
}