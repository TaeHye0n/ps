#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int> pq;
    
    for(string s : operations){
        char oper = s[0];
        int num = stoi(s.substr(2));
        if(oper == 'I'){
            pq.push(num);
        }
        else{
            if(num == 1 && !pq.empty()) pq.pop();
            else if(num == -1 && !pq.empty()){
                vector<int> temp;
                if(pq.size() == 1){
                    pq.pop();
                    continue;
                }
                while(pq.size() > 0){
                    temp.push_back(pq.top());
                    pq.pop();
                }
                temp.pop_back();
                for(int i = 0; i < temp.size() ;i++){
                    pq.push(temp[i]);
                }
            }
        }
    }
    
    if(pq.empty()){
        int a = 2;
        while(a--) answer.push_back(0);
    }
    else{
        answer.push_back(pq.top());
        if(pq.size() == 1) answer.push_back(pq.top());
        else{
            while(pq.size() > 1){
                    pq.pop();
                }
            answer.push_back(pq.top());
        }
    }
    return answer;
}