#include <string>
#include <vector>

using namespace std;

int solution(vector<int> common) {
    int answer = 0;
    
    vector<int> v1;
    vector<int> v2;
    
    for(int i = 0 ; i < common.size()-1; i++){
        int subs = common[i+1] - common[i];
        double div = (double)common[i+1]/common[i];
        v1.push_back(subs);
        v2.push_back(div);
    }
    
    if(v1[1] == v1[0]){
        return common.back()+v1[0];
    }
    else return common.back()*v2[0];
    return answer;
}