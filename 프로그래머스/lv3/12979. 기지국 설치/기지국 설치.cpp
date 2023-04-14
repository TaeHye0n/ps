#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int length = 0;
    int prev = 1;
    for(int i = 0; i < stations.size(); i++){
        int pos = stations[i];
        int st = 0, ed = 0;
        if(pos == 1){
            st = 1;
            ed = pos + w + 1;
            prev = ed;
        }
        else if(pos == n){
            st = pos-w-1;
            ed = n;
            length = st-prev+1;
            if(length <= 0) answer--;
            if(length <= (2*w+1)) answer++;
            else answer += ceil((double)length/(2*w+1));
            break;
        }
        else{
            st = pos-w-1;
            ed = pos+w+1;
            length = st-prev+1;
            prev = ed;
            if(length <= 0) answer--;
            if(length <= (2*w+1)) answer++;
            else answer += ceil((double)length/(2*w+1));
        }
        
        if(i == stations.size()-1){
            length = n-prev+1;
            if(length <= 0) answer--;
            if(length <= (2*w+1)) answer++;
            else answer += ceil((double)length/(2*w+1));
        }
    }

    return answer;
}