#include <string>
#include <vector>
#include <algorithm>
using namespace std;


int convertToInt(string time){
    string hour = time.substr(0,2);
    string min = time.substr(3,2);
    
    return stoi(hour)*60 + stoi(min);
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    
    sort(book_time.begin(), book_time.end());
    vector<int> endTime;
    for(int i = 0; i < book_time.size(); i++){
        bool flag = false;
        int st = convertToInt(book_time[i][0]);
        int ed = convertToInt(book_time[i][1]) + 10;
        
        if(endTime.empty()){
            endTime.push_back(ed);
            continue;
        }
        
        for(int j = 0; j < endTime.size(); j++){
            if(st >= endTime[j]){
                endTime[j] = ed;
                flag = true;
                break;
            }
        }
        if(flag) continue;
        endTime.push_back(ed);
    }
    
    answer = endTime.size();
    return answer;
}