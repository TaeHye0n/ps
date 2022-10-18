#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

vector<int> temp;
set<int> numbers;

void solve(){
    int sum = 0;
     for(int i = 0; i < temp.size(); i++){
         sum += temp[i];
     }
    numbers.insert(sum);
}


int solution(vector<int> elements) {
    int answer = 0;
    int size = elements.size();
    for(int i = 0; i < size;i++){
        elements.push_back(elements[i]);
    }
    for(int i = 0; i < elements.size(); i++){
        temp.push_back(elements[i]);
        solve();
        int cnt = 1;
        for(int j = i+1 ; j < elements.size(); j++){
            temp.push_back(elements[j]);
            solve();
            cnt++;
            if(cnt == size) break;
        }
        temp.clear();
    }
    answer = numbers.size();
    return answer;
}