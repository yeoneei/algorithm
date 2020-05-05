//
//  4008.cpp
//  backjoon
//
//  Created by 조연희 on 09/01/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
int T,n;
int cnt[5];
int op[12];
int num[12];
int opIdx=0;
int maxV;
int minV;
void dfs(int time){
    if(time==n-1){
        int sum=num[0];
        for(int i=0; i<n-1;i++){
            if(op[i]==1){
                sum+=num[i+1];
            }else if(op[i]==2){
                sum-=num[i+1];
            }else if(op[i]==3){
                sum*=num[i+1];
            }else{
                sum/=num[i+1];
            }
        }
        //cout<<sum<<endl;
        maxV = max(maxV, sum);
        minV = min(minV, sum);
        return ;
        
        
    }
    for(int i=1;i<5;i++){
        if(cnt[i]==0)continue;
        cnt[i]--;
        op[opIdx++]=i;
        dfs(time+1);
        opIdx--;
        cnt[i]++;
    }
}

int main(){
    cin>>T;
    for(int t=1; t<=T;t++){
        cin>>n;
        maxV=0;
        minV= 100000000;
        for(int i=1; i<5;i++){
            cin>>cnt[i];
        }
        for(int i=0;i<n;i++){
            cin>>num[i];
        }
        dfs(0);
        cout<<"#"<<t<<" "<<maxV-minV<<endl;
    }
}
