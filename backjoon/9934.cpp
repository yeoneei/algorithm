//
//  9934.cpp
//  backjoon
//
//  Created by 조연희 on 24/02/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int d;
int tree[2048];
int dept[11][512];
int deptCnt[11];
void print(int start, int end, int d){
    if(end-start<0) return;
    int mid = (start+end)/2;
    dept[d][deptCnt[d]++]=tree[mid];
    if(start == end) return;
    print(start, mid-1, d+1);
    print(mid+1, end, d+1);
    
    
}

int main(){
    cin>>d;
    for(int i=0; i<(1<<d)-1;i++){
        cin>>tree[i];
    }
    print(0, (1<<d)-2,0);
    for(int i=0; i<11;i++){
        if(deptCnt[i]==0)continue;
        for(int j=0; j< deptCnt[i];j++){
            cout<<dept[i][j]<<" ";
        }
        cout<<endl;
    }
    
    
}
