#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<double> solution(int k, vector<vector<int>> ranges) {
    vector<double> answer;
    vector<int> v;
    v.push_back(k);
    
    while(k > 1){
        if(k%2 == 0){
            k/=2;
            v.push_back(k);
        }
        else{
            k = k*3 + 1;
            v.push_back(k);
        }
    }
    double area[10001] = {0,};
    
    for(int i = 0; i < v.size()-1; i++){
        double temp = (double)(v[i+1] + v[i]) /2;
        area[i+1] = area[i] + temp;
    }
    
    for(int i = 0; i < ranges.size(); i++){
        int a = ranges[i][0];
        int b = v.size() - 1 + ranges[i][1];
        if(a > b) answer.push_back(-1.0);
        else if(a == b) answer.push_back(0.0);
        else{
            answer.push_back(area[b]-area[a]);
        }
    }
    return answer;
}