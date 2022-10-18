#include <string>
#include <vector>

using namespace std;
vector<int>temp;
int answer;

void isZero(){
    int sum = 0;
    
    for(int i = 0; i < temp.size(); i++){
        sum += temp[i];
    }
    if(sum == 0) answer++;
}

void dfs(int idx, int cnt, vector<int> number){
    if(cnt ==3){
       isZero();
        return;
    }
    for(int i = idx; i < number.size(); i++){
        temp.push_back(number[i]);
        dfs(i+1, cnt+1, number);
        temp.pop_back();
    }
        
}

int solution(vector<int> number) {
    dfs(0,0,number);
    
    return answer;
}