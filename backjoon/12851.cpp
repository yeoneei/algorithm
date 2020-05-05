
//
//  12851.cpp
//  backjoon
//
//  Created by 조연희 on 24/03/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <queue>
#define MAX 100000
using namespace std;

int n,m;
int check [MAX+1];
queue<int> qu;
int cnt [MAX+1];
int main(){
    cin>>n>>m;
    if(n==m){
        cout<<0<<'\n';
        cout<<1;
        return 0;
    }
    
    qu.push(n);
    check[n]=0;
    int t=0;
    while(!qu.empty()){
        int s = qu.size();
        t++;
        while(s--){
            int x = qu.front();
            qu.pop();
            if(x==m){
                cout<<check[m]<<'\n';
                cout<<cnt[m];
                return 0;
            }
            for(int nx :{x-1,x+1,2*x}){
                if(nx<0 || nx>MAX) continue;
                if(check[nx]!=0 && check[nx]<t)continue;
                if(check[nx]==t){
                    cnt[nx]++;
                }
                if(check[nx]==0){
                    check[nx]=t;
                    cnt[nx]++;
                }
                qu.push(nx);
            }
            
        }
    }
    
}
