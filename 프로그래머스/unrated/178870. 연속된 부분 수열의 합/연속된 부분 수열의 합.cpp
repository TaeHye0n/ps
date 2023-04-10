#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int n = sequence.size();
    int st = 0, ed = 0;
    int sum = 0;
    int stIdx = 0, edIdx = 0;
    int length = 1000000001;
    while(st < n && ed <= n){
        if(sum >= k){
            sum -= sequence[st++];
        }
        else sum += sequence[ed++];
        if(sum == k) {
            int tempLength = ed-st;
            if(tempLength < length){
                length = tempLength;
                stIdx = st;
                edIdx = ed-1;
            }
            else if(tempLength == length){
                if(stIdx > st){
                    stIdx = st;
                    edIdx = ed-1;
                }
            }
        }
    }
    answer.push_back(stIdx);
    answer.push_back(edIdx);
    return answer;
}