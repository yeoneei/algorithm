//
//  1.cpp
//  backjoon
//
//  Created by 조연희 on 01/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

priority_queue<int,vector<int>,greater<int>> pq;

int n,m,temp;
int main(){
    cin>>n>>m;
    for(int i=0; i<n;i++){
        cin>>temp;
        if(pq.size()<=m){
            pq.push(temp);
        }else{
            int top = pq.top();
            pq.pop();
            pq.push(top+temp);
        }
    }
    int maxV=pq.top();
    while(!pq.empty()){
        maxV = max(pq.top(),maxV);
        pq.pop();
    }
    cout<<maxV<<endl;
}
