#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct tree{
    int idx;
    int x;
    int y;
    tree* left;
    tree* right;
};
vector<int> pre;
vector<int> post;
bool cmp(tree t1, tree t2){
    if(t1.y == t2.y) return t1.x < t2.x;
    return t1.y > t2.y;
}
void makeBinaryTree(tree* Root, tree* child){
    if(Root->x > child->x){
        if(Root->left == NULL){
            Root->left = child;
            return;
        }
        makeBinaryTree(Root->left, child);
    }
    else{
        if(Root->right == NULL){
            Root->right = child;
            return;
        }
        makeBinaryTree(Root->right, child);
    }
}

void preOrder(tree* Root){
    if(Root == NULL) return;
    pre.push_back(Root->idx);
    preOrder(Root->left);
    preOrder(Root->right);
}
void postOrder(tree* Root){
    if(Root == NULL) return;
    postOrder(Root->left);
    postOrder(Root->right);
    post.push_back(Root->idx);
}
vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
    vector<vector<int>> answer;
    vector<tree> trees;
    
    for(int i = 0; i < nodeinfo.size(); i++){
        int idx = i+1;
        int x = nodeinfo[i][0];
        int y = nodeinfo[i][1];
        trees.push_back({idx,x,y});
    }
    
    sort(trees.begin(), trees.end(), cmp);
    tree* Root = &trees[0];
    for(int i = 1; i < trees.size(); i++){
        makeBinaryTree(Root, &trees[i]);
    }
    preOrder(Root);
    postOrder(Root);
    answer.push_back(pre);
    answer.push_back(post);
    return answer;
}