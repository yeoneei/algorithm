//
//  13460.cpp
//  backjoon
//
//  Created by 조연희 on 24/02/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
#define MAX 50
using namespace std;

struct TreeNode{
    int idx;
    bool check;
    vector<TreeNode *> children;
    TreeNode():check(true){}
};

TreeNode *tree[50];
int answer=0;

bool leafcheck(TreeNode * root){
    int cnt=0;
    for(int i=0; i<root->children.size();i++){
        if(root->children[i]->check==false)continue;
        cnt++;
    }
    return cnt==0;
}
void dfs(TreeNode * root){
    if(root->check==false) return;
    if(leafcheck(root)){
        answer++;
        return;
    }
    for(int i=0; i<root->children.size();i++){
        dfs(root->children[i]);
    }
}
int n,m, root,temp;
int main(){
    cin>>n;
    for(int i=0; i<n; i++) tree[i] = new TreeNode();
    for(int i=0; i<n;i++){
        cin>>temp;
        if(temp==-1){
            root =i;
            continue;
        }
        tree[i]->idx=i;
        tree[temp]->children.push_back(tree[i]);
    };
    cin>>m;
    tree[m]->check=false;
    dfs(tree[root]);
    cout<<answer<<endl;
}

