//
//  1697.cpp
//  backjoon
//
//  Created by 조연희 on 29/07/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <queue>
#define MAX 100000
using namespace std;
queue<int>qu;
int n,m;
int minX=MAX;
int countA;
bool check[MAX];
void bfs(){
    if(qu.empty()) return;
    while(!qu.empty()){
        int size = (int)qu.size();
        countA++;
        for(int i=0; i<size; i++){
            int temp = qu.front();
            qu.pop();
            if(minX != MAX) return;
            if( 0<=temp-1 && temp-1<=MAX && check[temp-1]==0){
                if(temp-1 == m && minX>countA){
                    minX= countA;
                    break;
                }
                check[temp-1]=1;
                qu.push(temp-1);
            }
            if(0<=temp+1 && temp+1 <=MAX&& check[temp+1]==0){
                if(temp+1 == m && minX>countA){
                    minX = countA;
                    break;
                }
                check[temp+1]=1;
                qu.push(temp+1);
            }
            if(0<=2*temp && 2*temp <=MAX){
                if(2*temp ==m && minX>countA && check[2*temp]==0){
                    minX = countA;
                }
                check[2*temp]=1;
                qu.push(2*temp);
            }
        }
    }
}

int main(){
    cin>>n>>m;
    qu.push(n);
    check[n]=1;
    bfs();
    cout<<minX<<endl;
}
