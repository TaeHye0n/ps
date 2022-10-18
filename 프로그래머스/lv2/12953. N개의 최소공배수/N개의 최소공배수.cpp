#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    bool flag = false;
    int a = 0;
    
    while(!flag){
          a++;
        for(int i = 0; i < arr.size(); i++){
            if(a % arr[i] != 0 ){
                flag = false;
                break;
            }
                
            else flag = true;
        }
        answer = a;
    }
    return answer;
}