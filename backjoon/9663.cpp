//
//  9663.cpp
//  backjoon
//
//  Created by 조연희 on 15/08/2019.
//  Copyright © 2019 조연희. All rights reserved.
//
#include <iostream>
#include <string.h>
using namespace std;

int queen[15];
int n;
int countQ;
bool pomising(int level){
    for(int i=1; i<level;i++){
        if(queen[i]== queen[level]) return false;
        else if(abs(level-i)==abs(queen[level]-queen[i])) return false;
    }
    return true;
}

void queens(int level){
    if(!pomising(level)){
        return;
    }
    else if(level==n){
        countQ++;
        return;
    }
    if(level>=n){
        return;
    }
    for(int i=1; i<=n;i++){
        queen[level+1]=i;
        queens(level+1);
    }
    
}
int t;
int main(){
    cin>>t;
    for(int tc=1; tc<=t;tc++){
        cin>>n;
        memset(queen,0,sizeof(queen));
        countQ=0;
        queens(0);
        cout<<'#'<<tc<<" "<<countQ<<endl;
    }
}
