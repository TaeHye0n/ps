#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());
    
    int Aidx = 0;
    int Bidx = 0;
    int n = A.size();
    while(Aidx < n){
        if(A[Aidx] < B[Bidx]){
            Aidx++;
            Bidx++;
            answer++;
        }
        else if(A[Aidx] == B[Bidx]){
            Aidx++;
        }
        else{
            Aidx++;
        }
    }
    return answer;
}