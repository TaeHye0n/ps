#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> order) {
    int answer = 0;
    stack<int> sub;
    sub.push(0);
    
    int index = 0;
    for(int i = 1; i <= order.size(); i++){
        if(order[index] == i){
            index++;
        }
        else if(order[index] == sub.top()){
            sub.pop();
            index++;
            i--;
        }
        else sub.push(i);
        
    }
    
    while(sub.size() > 1){
        if(sub.top() == order[index]){
            index++;
            sub.pop();
        }
        else break;
    }
    return index;
}