#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(int a, int b){
    return a > b;
}

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    int size = A.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), cmp);
     int i = 0;
    while(i < size){
        answer += A[i] * B[i]; 
        i++;
    } 
   
    
    return answer;
}