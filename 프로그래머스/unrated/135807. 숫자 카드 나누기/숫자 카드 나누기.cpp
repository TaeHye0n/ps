#include <string>
#include <vector>
#include <numeric>
#include <iostream>
using namespace std;

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    int gcdA = arrayA[0];
    for(int i = 1; i < arrayA.size(); i++){
         gcdA = gcd(gcdA, arrayA[i]);
    }    
    int gcdB = arrayB[0];
    for(int i = 1; i < arrayB.size(); i++){
         gcdB = gcd(gcdB,arrayB[i]);
    }
    
    bool flag1 = false;
    for(int a : arrayB){
        if(a % gcdA == 0){
            flag1 = true;
            break;
        }
    }
    if(!flag1) answer = gcdA;
    bool flag2 = false;
    for(int a : arrayA){
        if(a % gcdB == 0){
            flag2 = true;
            break;
        }
    }
    if(!flag2) answer = max(answer,gcdB);
    return answer;
}