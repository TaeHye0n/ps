#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <iostream>

using namespace std;

int convertToDay(string s){
    int month = stoi(s);
    return month*28;
}

int calculateDay(string today, string s){
    istringstream iss(today);
    string tYear, tMonth, tDay;
    string token;
    vector<string> temp;
    while(getline(iss, token, '.')){
        temp.push_back(token);
    }
    tYear = temp[0];
    tMonth = temp[1];
    tDay = temp[2];
    
    istringstream iss2(s);
    string pYear, pMonth, pDay;
    vector<string> temp2;
    while(getline(iss2, token, '.')){
        temp2.push_back(token);
    }
    pYear = temp2[0];
    pMonth = temp2[1];
    pDay = temp2[2];
    
    int year = stoi(tYear) - stoi(pYear);
    int month = stoi(tMonth) - stoi(pMonth);
    int day = stoi(tDay) - stoi(pDay);
    
    return year*12*28 + month*28 + day;
}
vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    map<char, int> duration;
    
    for(string s : terms){
        char c = s[0];
        string dur = s.substr(2);
        duration.insert({c,convertToDay(dur)});
    }
    
    for(int i = 0; i < privacies.size(); i++){
        char term = privacies[i][11];
        string prevDate = privacies[i].substr(0,10);
        int left = calculateDay(today, prevDate);
        
        if(left >= duration[term]) answer.push_back(i+1);
    }
    
    return answer;
}