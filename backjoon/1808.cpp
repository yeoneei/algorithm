//
//  1808.cpp
//  backjoon
//
//  Created by 조연희 on 02/05/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int T;
bool num[10];
int input;
int ansLen=1000000;
void bfs(){
    queue<pair<int,int>>qu;
    qu.push(make_pair(0,0));
    while(!qu.empty()){
        int x= qu.front().first;
        int len = qu.front().second;
        
        if(x==input){
            ansLen = min(ansLen,len+1);
            break;
        }
        qu.pop();
        if(x>input) continue;
        int newAnwer=0;
        for(int i=0; i<10;i++){
            if(!num[i])continue;
            newAnwer = x*10+i;
            if(newAnwer!=x){
                qu.push(make_pair(newAnwer, len+1));
            }
            newAnwer = x*i;
            if(newAnwer!=x){
                qu.push(make_pair(newAnwer, len+2));
            }
        }
    }
}

int main(){
    cin>>T;
    for(int tc=1; tc<=T;tc++){
        for(int i=0; i<10;i++){
            cin>>num[i];
        }
        cin>>input;
        ansLen=1000000;
        bfs();
        cout<<'#'<<tc<<" ";
        if(ansLen!=1000000){
            cout<<ansLen<<endl;
        }else{
            cout<<-1<<endl;
        }
    }
    
}
