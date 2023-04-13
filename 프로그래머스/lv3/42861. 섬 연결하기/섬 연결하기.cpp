#include <string>
#include <vector>
#include <algorithm>
#define MAX 101
using namespace std;

int root[MAX];
bool cmp(vector<int> v1, vector<int> v2){
    return v1[2] < v2[2];
}
int getParent(int node){
    if(root[node] == node) return node;
    return root[node] = getParent(root[node]);
}
void Union(int nodeA, int nodeB){
    nodeA = getParent(nodeA);
    nodeB = getParent(nodeB);
    root[nodeB] = nodeA;
}
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    
    for(int i = 0; i < n; i++){
        root[i] = i;
    }
    sort(costs.begin(), costs.end(), cmp);
    
    for(int i = 0; i < costs.size(); i++){
        int nodeA = costs[i][0];
        int nodeB = costs[i][1];
        int cost = costs[i][2];
        
        if(getParent(nodeA) != getParent(nodeB)){
            Union(nodeA, nodeB);
            answer += cost;
        }
    }
    
    
    return answer;
}