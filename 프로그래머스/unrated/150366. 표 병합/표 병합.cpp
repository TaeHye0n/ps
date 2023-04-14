#include <string>
#include <vector>
#include <sstream>

using namespace std;
int parent[2501];
string cell[2501];

int makePos(int r, int c){
    return (r-1)*50 + c;
}
vector<string> solution(vector<string> commands) {
    vector<string> answer;
    
    for(int i = 1; i <= 2500; i++){
        parent[i] = i;
        cell[i] = "EMPTY";
    }
    
    for(int i = 0; i <commands.size();i++){
        stringstream ss(commands[i]);
        string token;
        vector<string> temp;
        while(ss>>token) temp.push_back(token);
        
        if(temp[0] == "UPDATE"){
            if(temp.size() == 4){
                int r = stoi(temp[1]);
                int c = stoi(temp[2]);
                int pos = makePos(r,c);
                int root = parent[pos];
                cell[root] = temp[3];
            }
            else{
                string val1 = temp[1], val2 = temp[2];
                for(int i =1; i <= 2500; i++){
                    if(cell[i] == val1) cell[i] = val2;
                }
            }
        }
        else if(temp[0] =="MERGE"){
            int pos1 = makePos(stoi(temp[1]),stoi(temp[2]));
            int pos2 = makePos(stoi(temp[3]),stoi(temp[4]));
            int root1 = parent[pos1];
            int root2 = parent[pos2];
            
            if(root1 != root2){
                for(int i = 1; i <= 2500; i++){
                    if(parent[i] == root2) parent[i] = root1;
                }
                string value1 = cell[root1];
                string value2 = cell[root2];
                
                if(value1 == "EMPTY" && value2 != "EMPTY"){
                    cell[root1] = value2;
                }
            }
        }
        else if(temp[0] == "UNMERGE"){
            int pos = makePos(stoi(temp[1]), stoi(temp[2]));
            int root = parent[pos];
            string value = cell[root];
            for(int i = 1; i <= 2500; i++){
                if(parent[i] == root){
                    parent[i] = i;
                    cell[i] = "EMPTY";
                }
            }
            cell[pos] = value;
        }
        else{
            int pos = makePos(stoi(temp[1]), stoi(temp[2]));
            int root = parent[pos];
            answer.push_back(cell[root]);
        }
    }
    return answer;
}