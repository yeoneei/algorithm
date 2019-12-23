//
//  1697-2.cpp
//  backjoon
//
//  Created by 조연희 on 01/12/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
queue<int> qu;
int check[100001];

int main(){
    int n,m;
    cin>>n>>m;
    qu.push(n);
    
    while(!qu.empty()){
        int v = qu.front();
        qu.pop();
        if(v==m) break;
        if(v-1>=0 && v-1<=100000 && check[v-1]==0){
            qu.push(v-1);
            check[v-1]= check[v]+1;
        }
        if(v+1>=0 && v+1<=100000 &&check[v+1]==0){
            qu.push(v+1);
            check[v+1] = check[v]+1;
        }
        if(v*2>=0 && v*2<=100000 && check[v*2]==0){
            qu.push(v*2);
            check[v*2] = check[v]+1;
        }
    }
    cout<<check[m]<<endl;

}
