#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    int num[10] = {'0','1','2','3','4','5','6','7','8','9'};
    map<char,int> m1;
    map<char,int> m2;
    vector<char> v;
    
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < X.length(); j++){
            if(X[j] == num[i]) m1[num[i]]++;
        }
    }
    
    for(int i = 0; i < 10; i++){
        for(int j = 0 ; j < Y.length(); j++){
            if(Y[j] == num[i]) m2[num[i]]++;
        }
    }
    
    for(int i = 0; i < 10 ;){
        if(m1[num[i]] > 0 && m2[num[i]] >0){
            m1[num[i]]--;
            m2[num[i]]--;
            v.push_back(num[i]);
        }
        else i++;
    }
    sort(v.begin() ,v.end());
    while(!v.empty()){
        answer += v[v.size()-1];
        v.pop_back();
    }
    if(answer[0] == '0') answer = "0";
    if(answer == "") answer = "-1";
    
    return answer;
}