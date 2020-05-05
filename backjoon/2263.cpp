//
//  2263.cpp
//  backjoon
//
//  Created by 조연희 on 24/02/2020.
//  Copyright © 2020 조연희. All rights reserved.
//
#include <iostream>
using namespace std;
int n;
int inorder[100002];
int postorder[100002];
int idxInorder[100002];

void preOrdr(int inS, int inE, int postS, int postE){
    if(inS > inE ||postS > postE)return;
    int root = postorder[postE];
    cout<<root<<" ";
    int idx = idxInorder[root];
    int len = idx-inS;
    
    preOrdr(inS, idx-1, postS, postS+len-1);
    preOrdr(idx+1, inE, postS+len, postE-1);
    
}
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>inorder[i];
        idxInorder[inorder[i]]=i;
    }
    for(int i=0; i<n;i++){
        cin>>postorder[i];
    }
    preOrdr(0,n-1,0,n-1);
}
