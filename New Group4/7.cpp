//
//  7.cpp
//  backjoon
//
//  Created by 조연희 on 11/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;


int N,M,K;
vector<int> vc;
vector<bool>check;


bool answerCheck(){
    if(M-vc[vc.size()-1]>K) return false;
    for(int i=0; i<vc.size();i++){
        cout<<vc[i]<<" ";
    }
    cout<<endl;
    int idx=0;
    int arr[2]={0,0};
    int past = vc[0];
    arr[idx++]=vc[0];
    vc.push_back(M);
    for(int i=1; i<vc.size();i++){
        arr[idx++] += (vc[i]-past);
        idx%=2;
        past = vc[i];
    }
    vc.pop_back();
    return arr[0]==arr[1];
}

long long CNT=0;
void dfs(int cnt,int v){
    if(v>=M)return;
    if(cnt==N-1 && answerCheck()){
        CNT++;
    }
    if(cnt>=N)return;
    for(int i=v; i<v+K;i++){
        if(check[i])continue;
        check[i]=1;
        vc.push_back(i);
        dfs(cnt+1,i+1);
        vc.pop_back();
        check[i]=0;
    }
}

int solution(int n,int m,int k){
    N=n;M=m;K=k;
    check.resize(m+1);
    dfs(0,1);
    return CNT;
}

int main(){
    cout<<solution(3,8,4);
}
