//
//  17779.cpp
//  backjoon
//
//  Created by 조연희 on 05/01/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define MAX 21
using namespace std;

int n;
int allSum=0;
int map[MAX][MAX];
bool check[MAX][MAX];
vector<int> answer;

bool ragne(int i, int d1, int d2){
    int x =i/n;
    int y =i%n;
    x++;y++;
    memset(check,0,sizeof(check));
    // d1, d2 ≥ 1, 1 ≤ x < x+d1+d2 ≤ N, 1 ≤ y-d1 < y < y+d2 ≤ N
    if(1 <= x && x+d1+d2 <=n && 1<= y-d1 && y-d1<y && y<y+d2 && y+d2 <=n){
        //결계치기
        for(int i=0;i<=d1;i++){
            check[x+i][y-i]=1;
            check[x+d2+i][y+d2-i]=1;
        }
        for(int i=1;i<=d2;i++){
            check[x+i][y+i]=1;
            check[x+d1+i][y-d1+i]=1;
        }
        
        return true;
    }
   return false;
}
bool ragne2(int s, int d1, int d2,int nx, int ny,int t){
    int x = s/n;
    int y= s%n;
    x++;y++;
    if(t==2){
        //(x, y), (x+1, y+1), ..., (x+d2, y+d2)
        for(int i=0;i<=d2;i++){
            if((nx==x+i) && (ny<=y+i)){
                return false;
            }
        }
    }else{
        //(x+d2, y+d2), (x+d2+1, y+d2-1), ..., (x+d2+d1, y+d2-d1)
        for(int i=0; i<=d1;i++){
            if((nx == x+d2+i) && (ny<=y+d2-i)){
                return false;
            }
        }
    }
    return true;
}
void getValue(int s, int d1, int d2){
    int x = s/n;
    int y = s%n;
    x++;y++;
    int all=0;
    int sum=0;
    vector<int> v;
    //1번 선거구: 1 ≤ r < x+d1, 1 ≤ c ≤ y
    for(int i=1; i<x+d1;i++){
        for(int j=1; j<=y;j++){
            if(check[i][j]!=1){
                sum+=map[i][j];
            }else{
                break;
            }
        }
    }
    v.push_back(sum);
    all+=sum;
    sum=0;
    //2번 선거구: 1 ≤ r ≤ x+d2, y < c ≤ N
    for(int i=1; i<=x+d2;i++){
        for(int j=y+1; j<=n;j++){
            if(ragne2(s,d1,d2,i,j,2)){
                sum+=map[i][j];
            }
        }
    }
    v.push_back(sum);
    all+=sum;
    sum=0;
    //3번 선거구: x+d1 ≤ r ≤ N, 1 ≤ c < y-d1+d2
    for(int i=x+d1;i<=n;i++){
        for(int j=1;j<y-d1+d2;j++){
            if(check[i][j]!=1){
                sum+=map[i][j];
            }else{
                break;
            }
        }
    }
    v.push_back(sum);
    all+=sum;
    sum=0;
    //4번 선거구: x+d2 < r ≤ N, y-d1+d2 ≤ c ≤ N
    for(int i=x+d2+1; i<=n;i++){
        for(int j=y-d1+d2; j<=n;j++){
            
            if(ragne2(s,d1,d2,i,j,4)){
                
                sum+=map[i][j];
            }
        }
    }
    all+=sum;
    v.push_back(sum);
    v.push_back(allSum-all);
    
    sort(v.begin(),v.end());
    answer.push_back(v[v.size()-1]-v[0]);
}

void dfs(){
    for(int i=0; i<n*n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1; k<=n;k++){
                if(ragne(i,j,k)){
                    getValue(i,j,k);
                }
            }
        }
    }
}


int main(){
    cin>>n;
    for(int i=1; i<=n;i++){
        for(int j=1; j<=n;j++){
            cin>>map[i][j];
            allSum+=map[i][j];
        }
    }
   
    dfs();
    sort(answer.begin(),answer.end());
    cout<<answer[0];
}
