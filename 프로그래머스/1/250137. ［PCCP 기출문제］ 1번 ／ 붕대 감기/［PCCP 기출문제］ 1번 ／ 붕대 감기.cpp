#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(vector<int> bandage, int health, vector<vector<int>> attacks) {
    int answer = 0;
    
    int curHealth = health;
    int lastAtkTime = 0;
    for (auto attack : attacks) {
        int time = attack[0];
        int dmg = attack[1];
        
        int tempo = time - lastAtkTime;
        lastAtkTime = time;
        
        int heal = (tempo - 1) * bandage[1] + ((tempo - 1)/ bandage[0]) * bandage[2];
        cout << tempo << endl;
        
        curHealth = curHealth + heal > health ? health : curHealth + heal;
        
        curHealth -= dmg;
        
        if (curHealth <= 0) return -1;

    }
    return curHealth;
}