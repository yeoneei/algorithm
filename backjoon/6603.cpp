//
//  6603.cpp
//  backjoon
//
//  Created by 조연희 on 13/05/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

int arr[13];
bool check[13];
int n;

void dfs(int cnt,int idx){
    if(cnt == 6){
        for(int i=0; i<n;i++){
            if(check[i]==1){
                cout<<arr[i]<<" ";
            }
        }
        cout<<endl;
        return;
    }
    if(cnt>=6) return;
    
    for(int i=idx;i<n;i++){
        if(check[i]==1) continue;
        check[i]=1;
        dfs(cnt+1, i);
        check[i]=0;
    }
}

int main(){
    while(1){
        cin>>n;
        if(n==0){
            break;
        }
        for(int i=0; i<n;i++){
            cin>>arr[i];
        }
        dfs(0,0);
        cout<<endl;
    }
    
}
