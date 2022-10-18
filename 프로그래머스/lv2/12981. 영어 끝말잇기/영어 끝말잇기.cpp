#include <string>
#include <vector>
#include <iostream>
#include <map>
using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    map<string , int> m;
    m[words[0]]++;
   
    for(int i = 1; i < words.size(); i++){
        int num = i%n + 1;
        int order = i/n + 1;
        m[words[i]]++;
        if(m[words[i]] != 1 || words[i].front() != words[i-1].back()) {
            cout << i << ' ' << num << ' ' << order;
            return {num,order};
        }
        
    }
   answer = {0,0};

    return answer;
}