#include <string>
#include <vector>
#include <cmath>
using namespace std;

int solution(int n) {
    int answer = 0;
    int cnt = 0;
    int cnt_2 = 0;
    int temp = 0;
    int i = n + 1;
    while(n){
        if(n % 2 == 1) cnt++;
        n /= 2;
    }
    
    
     while(1){
         temp = i;
        while(temp){  
            if(temp % 2 == 1) cnt_2++;
            temp /= 2;
        }
        
        if(cnt == cnt_2) break;
         else cnt_2 = 0;
         i++;
    }
    
    answer = i;
   
    return answer;
}