//
//  3980.cpp
//  backjoon
//
//  Created by 조연희 on 27/03/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <string.h>
using namespace std;

int map[11][11];
int T;
int arr[11];
bool check[11];
int answer=0;
void dfs(int cnt,int v){
    if(cnt==11){
        int sum=0;
        for(int i=0; i<11;i++){
            if(map[i][arr[i]]==0)return;
            sum+=map[i][arr[i]];
        }
        answer = max(answer,sum);
    }
    
    for(int i=0;i<11;i++){
        if(check[i] || map[cnt][i]==0 )continue;
        check[i]=1;
        arr[cnt]=i;
        dfs(cnt+1,i+1);
        check[i]=0;
    }
}

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>T;
    for(int t=0; t<T;t++){
        answer=0;
        memset(check,0,sizeof(check));
        for(int i=0; i<11;i++){
            for(int j=0; j<11;j++){
                cin>>map[i][j];
            }
        }
        dfs(0, 0);
        cout<<answer<<'\n';
    }
}
