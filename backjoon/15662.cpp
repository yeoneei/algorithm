//
//  15662.cpp
//  backjoon
//
//  Created by 조연희 on 11/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <deque>
#include <queue>
using namespace std;

int t,m,num,c;
deque<int> de[1000];


int main(){
    cin>>t;
    for(int i=0; i<t;i++){
        for(int j=0; j<8;j++){
            char temp;
            cin>>temp;
            de[i].push_back((int)(temp-'0'));
        }
    }
    cin>>m;
    for(int i=0; i<m;i++){
        cin>>num>>c;
        num--;
        queue<pair<int,int>> qu;
        qu.push(make_pair(num,c));
        int now = c;
        for(int j=num-1; j>=0;j--){
            if(de[j+1][6]==de[j][2])break;
            now = -1*now;
            qu.push(make_pair(j, now));
        }
        now = c;
        for(int j= num+1; j<t;j++){
            if(de[j-1][2]==de[j][6])break;
            now = -1*now;
            qu.push(make_pair(j,now));
        }
        while(!qu.empty()){
            int num = qu.front().first;
            int dir = qu.front().second;
            qu.pop();
            if(dir==1){
                int temp = de[num].back();
                de[num].pop_back();
                de[num].push_front(temp);
            }
            if(dir==-1){
                int temp = de[num].front();
                de[num].pop_front();
                de[num].push_back(temp);
            }
        }
    }
    int cnt=0;
    for(int i=0; i<t;i++){
        if(de[i][0]==1)cnt++;
    }
    cout<<cnt;
}
