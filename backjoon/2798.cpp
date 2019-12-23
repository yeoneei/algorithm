//
//  2798.cpp
//  backjoon
//
//  Created by 조연희 on 12/08/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int n,m;
int arr[100];
bool check[100];
int sum=0;
vector<int> answer;

void dfs(int cnt){
    if(cnt == 3 && sum <=m){
        answer.push_back(sum);
        return;
    }
    if (cnt>=3 || sum>m){
        return;
    }
    
    for(int i=0; i<n;i++){
        if(check[i]==1) continue;
        check[i]=1;
        sum+=arr[i];
        dfs(cnt+1);
        sum-=arr[i];
        check[i]=0;
    }
}


int main(){
    cin>>n>>m;
    for(int i=0; i<n;i++){
        cin>>arr[i];
    }
    dfs(0);
    int diff=m;
    int sumValue;
    for(int i=0; i<answer.size();i++){
        if(abs(answer[i]-m)<diff){
            diff = abs(answer[i]-m);
            sumValue = answer[i];
        }
    }
    
    cout<<sumValue<<endl;
}

