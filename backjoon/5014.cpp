//
//  5014.cpp
//  backjoon
//
//  Created by 조연희 on 13/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <queue>
#define MAX 1000000
using namespace std;

int f,s,g,u,d;
int check[MAX+1];
int main(){
    cin>>f>>s>>g>>u>>d;
    queue<int> qu;
    qu.push(s);
    for(int i=1; i<=f;i++){
        check[i]=-1;
    }
    check[s]=0;
    while(!qu.empty()){
        int x = qu.front();
        qu.pop();
        if(x==g){
            cout<<check[x];
            return 0;
        }
        if(x+u<=f && check[x+u]==-1){
            check[x+u]=check[x]+1;
            qu.push(x+u);
            
        }
        if(x-d>=1 && check[x-d]==-1){
            check[x-d]=check[x]+1;
            qu.push(x-d);
        }
    }
    cout<<"use the stairs";
}
