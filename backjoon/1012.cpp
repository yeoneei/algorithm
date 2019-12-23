//
//  1012.cpp
//  backjoon
//
//  Created by 조연희 on 11/07/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

int arr[50][50];
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int N,M,num;

int dfs(int x, int y){
    if(arr[y][x]==0){
        return 0;
    }else{
        arr[y][x]=0;
        for(int i=0; i<4;i++){
            int newX = x+dx[i];
            int newY = y+dy[i];
            if(0<= newX && newX <N && 0<=newY && newY<M && arr[newY][newX]==1){
                dfs(newX,newY);
            }
        }
        return 1;
    }
    return 0;
    
}

int main(){
    int T;
    cin>>T;
    for(int tc =0; tc<T;tc++){
        cin>>N>>M>>num;
        for(int i=0; i<num;i++){
            int a,b;
            cin>>a>>b;
            arr[b][a]=1;
        }
        
        int count=0;
        for(int i=0; i<M;i++){
            for(int j=0; j<N;j++){
                int temp = dfs(j,i);
                if(temp!=0){
                    count++;
                }
            }
        }
        cout<<count<<endl;
    }
}
