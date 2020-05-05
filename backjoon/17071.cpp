//
//  17071.cpp
//  backjoon
//
//  Created by 조연희 on 16/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <queue>
#define MAX 500000
using namespace std;

int n,m;
int check[MAX+1];
int main(){
    cin>>n>>m;
    if(m==MAX){
        cout<<-1;
        return 0;
    }
    for(int i=0; i<=m;i++){
        check[i]=-1;
    }
    queue<int> qu;
    qu.push(n);
    check[n]=0;
    int t=1;
    
    cout<<-1;
}
