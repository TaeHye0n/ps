#include <string>
#include <vector>
#include <iostream>
using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int deliveryPoint = n - 1;
    int pickupPoint = n - 1;
    int goDist = -1, comeDist = -1;
    bool flag = true;
    while(flag){
        int carry = cap;
        for(int i = deliveryPoint; i >= 0; i--){
            if(carry >= deliveries[i]){
                if(deliveries[i] != 0 && goDist < i) goDist = i;
                carry -= deliveries[i];
                deliveries[i] = 0;
                deliveryPoint = i;
            }
            else if(carry < deliveries[i]){
                deliveryPoint = i;
                deliveries[i] -= carry;
                carry = 0;
                if(goDist < i) goDist = i;
                break;
            }
        }
        
        carry = cap;
        for(int i = pickupPoint; i >= 0; i--){
            if(carry >= pickups[i]){
                if(pickups[i] != 0 && comeDist < i) comeDist = i;
                carry -= pickups[i];
                pickups[i] = 0;
                pickupPoint = i;
            }
            else if(carry < pickups[i]){
                pickups[i] -= carry;
                carry = 0;
                pickupPoint = i;
                if(comeDist < i) comeDist = i;
                break;
            }
        }
        // cout << goDist << " " << comeDist << " " << deliveries[0] << endl;
        
        answer = answer + (long long)max(comeDist+1,goDist+1)*2;
        comeDist = -1; goDist = -1;
        if(deliveryPoint == 0 && pickupPoint == 0 && deliveries[0] ==0 && pickups[0] ==0) flag = false;
    }
    return answer;
}