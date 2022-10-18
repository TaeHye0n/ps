#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int sum = brown + yellow;
    for(int h = 3; h < sum ; h++){
        if(sum % h == 0){
            int width = sum / h;
            if((h-2)*(width-2) == yellow){
                answer.push_back(width);
                answer.push_back(h);
                break;
            }
        }
    }
    
    return answer;
}