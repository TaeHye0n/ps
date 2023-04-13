#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct subject{
    string task;
    int stTime;
    int leftTime;
};
bool cmp(subject s1, subject s2){
    return s1.stTime < s2.stTime;
}
int changeToInt(string stTime){
    int hour = stoi(stTime.substr(0,2));
    int min = stoi(stTime.substr(3));
    
    return hour*60 + min;
}
vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer; // 끝난 과제
    stack<subject> s; // 잠시 멈춘 과제
    vector<subject> subjects;
    
    for(int i = 0; i < plans.size(); i++){
        string task = plans[i][0];
        int stTime = changeToInt(plans[i][1]);
        int duration = stoi(plans[i][2]);
        
        subjects.push_back({task, stTime, duration});
    }
    sort(subjects.begin(), subjects.end(), cmp);
    
    for(int i = 1; i < subjects.size(); i++){
        if(subjects[i].stTime < subjects[i-1].stTime + subjects[i-1].leftTime){
            subjects[i-1].leftTime -= (subjects[i].stTime - subjects[i-1].stTime);
            s.push(subjects[i-1]);
        }
        else if(subjects[i].stTime == subjects[i-1].stTime + subjects[i-1].leftTime){
            answer.push_back(subjects[i-1].task);
        }
        else{
            answer.push_back(subjects[i-1].task);
            int newTime = subjects[i].stTime-subjects[i-1].stTime - subjects[i-1].leftTime;
            while(!s.empty()){
                if(newTime >s.top().leftTime){
                    answer.push_back(s.top().task);
                    newTime -= s.top().leftTime;
                    s.pop();
                }
                else if ( newTime == s.top().leftTime){
                    answer.push_back(s.top().task);
                    newTime = 0;
                    s.pop();
                    break;
                }
                else{
                   s.top().leftTime -= newTime;
                    newTime = 0;
                    break;
                }
            }
        }
    }
    answer.push_back(subjects.back().task);
    while(!s.empty()){
        answer.push_back(s.top().task);
        s.pop();
    }
    return answer;
}