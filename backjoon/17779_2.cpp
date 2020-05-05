//
//  17779_2.cpp
//  backjoon
//
//  Created by 조연희 on 25/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <string.h>
using namespace std;

int mapSum=0;
int map[21][21];
bool check[21][21];
int N;
int d[2];
int answer=0;


void round(int x,int y, int d1, int d2){
    check[x][y]=1;
    for(int i=1; i<=d1;i++){
        check[x+i][y-i]=1;
    }
    for(int i=1; i<=d2;i++){
        check[x+i][y+i]=1;
    }
    for(int i=0; i<=d2;i++){
        check[x+d1+i][y-d1+i]=1;
    }
    for(int i=0; i<=d1;i++){
        check[x+d2+i][y+d2-i]=1;
    }
    
}

void getMin(int x,int y, int d1, int d2){
    int sum=0;
    int maxV=0;
    int minV=mapSum;
    int allSum=mapSum;
    
    //1 ≤ r < x+d1, 1 ≤ c ≤ y
    for(int i= 1; i<x+d1; i++){
        for(int j=1; j<=y;j++){
            if(check[i][j]==1)break;
            sum+=map[i][j];
        }
    }
    
    maxV = max(maxV, sum);
    minV = min(minV,sum);
    allSum-=sum;
    sum=0;
    //1 ≤ r ≤ x+d2, y < c ≤ N
    for(int i =1 ;i<=x; i++){
        for(int j =y+1; j<=N;j++){
            sum+=map[i][j];
        }
    }
    for(int i=x+1; i<=x+d2;i++){
        bool ch = false;
        for(int j=y+1; j<=N;j++){
            if(!ch && check[i][j]==1){
                ch= true;
                continue;
            }
            if(!ch)continue;
            sum+=map[i][j];
        }
    }
    
    
    maxV = max(maxV, sum);
    minV = min(minV,sum);
    allSum-=sum;
    sum=0;
    
    //x+d1 ≤ r ≤ N, 1 ≤ c < y-d1+d2
    for(int i=x+d1; i<=N;i++){
        for(int j=1;j<y-d1+d2;j++){
            if(check[i][j])break;
            sum+=map[i][j];
        }
    }
    
    
    maxV = max(maxV, sum);
    minV = min(minV,sum);
    allSum-=sum;
    sum=0;
    // x+d2 < r ≤ N, y-d1+d2 ≤ c ≤ N
    for(int i=x+d2+1; i<=x+d2+d1;i++){
        bool ch = false;
        for(int j = y-d1+d2 ; j<=N;j++){
            if(!ch && check[i][j]==1){
                ch=true;
                continue;
            }
            if(!ch)continue;
            sum+=map[i][j];
        }
    }
    for(int i= x+d2+d1+1; i<=N;i++){
        for(int j = y-d1+d2 ; j<=N;j++){
            sum+=map[i][j];
        }
    }
    maxV = max(maxV, sum);
    minV = min(minV,sum);
    allSum-=sum;
    
    maxV = max(maxV, allSum);
    minV = min(minV,allSum);
    
    answer = min(answer,maxV-minV);
}


void dfs(int i, int j, int cnt){
    //d1, d2 ≥ 1, 1 ≤ x < x+d1+d2 ≤ N, 1 ≤ y-d1 < y < y+d2 ≤ N
    if(cnt==2){
        //d1, d2 ≥ 1, 1 ≤ x < x+d1+d2 ≤ N, 1 ≤ y-d1 < y < y+d2 ≤ N
        if(d[0]>=1 && d[1]>=1 && (1<=i) && (i<i+d[0]+d[1]) && (i+d[0]+d[1]<=N) && 1<=(j-d[0])&& (j-d[0]<j) && (j<j+d[1]) && j+d[1]<=N){
            //경계치기
            
            memset(check,0,sizeof(check));
            round(i,j,d[0],d[1]);
            getMin(i,j,d[0],d[1]);
        }
        return;
        
    }
    for(int s=1; s<=N;s++){
        d[cnt]=s;
        dfs(i,j,cnt+1);
    }
}

int main(){
    cin>>N;
    for(int i=1; i<N+1;i++){
        for(int j=1; j<N+1;j++){
            cin>>map[i][j];
            mapSum+=map[i][j];
        }
    }
    answer= mapSum;
    for(int i=1; i<=N;i++){
        for(int j=1; j<=N;j++){
            dfs(i,j,0);
        }
    }
    cout<<answer;
}
