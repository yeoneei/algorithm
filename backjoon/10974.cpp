//
//  10974.cpp
//  backjoon
//
//  Created by 조연희 on 28/01/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

int n;
bool check[11];
int arr[11];
int arrIdx=0;
int ans=10000000;
int map[11][11];
void dfs(int cnt){
    if(cnt==n){
        arr[n]=arr[0];
        int sum=0;
        for(int i=0; i<n;i++){
            if(map[arr[i]][arr[i+1]]==0) return;
            sum+=map[arr[i]][arr[i+1]];
            
        }
        ans = min(ans,sum);
        return;
    }
    for(int i=0; i<n;i++){
        if(check[i]) continue;
        check[i]=1;
        arr[arrIdx++]=i;
        dfs(cnt+1);
        check[i]=0;
        arrIdx--;
    }
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n;
    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            cin>>map[i][j];
        }
    }
    dfs(0);
    cout<<ans;
}
