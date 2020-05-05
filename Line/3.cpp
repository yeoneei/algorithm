//
//  3.cpp
//  backjoon
//
//  Created by 조연희 on 01/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int n,fi,se;
int cnt=0;
priority_queue<pair<int,int>>pq;
vector<int> endList;
int main(){
    cin>>n;
    while(n--){
        cin>>fi>>se;
        pq.push(make_pair(se, fi));
    }
    
    endList.push_back(pq.top().second);
    pq.pop();
    while(!pq.empty()){
        int start = pq.top().second;
        int endTime = pq.top().first;
        pq.pop();
        bool check=false;
        for(int i=0; i<endList.size();i++){
            if(endList[i]>=endTime){
                endList[i]=start;
                check=true;
                break;
            }
        }
        if(!check){
            endList.push_back(start);
        }
    }
    cout<<endList.size();
}
