#include <iostream>
#include <cmath>

using namespace std;
int solution(int n)
{
    int answer = 0;
    int a = 0;
    
    while( n != 0){
        answer  = answer +  n % 10;
        n /= 10;
        
    }    
   
   
    

    return answer;
}