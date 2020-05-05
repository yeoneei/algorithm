//
//  4466.cpp
//  backjoon
//
//  Created by 조연희 on 28/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

int T,n,k;
int arr[100];

int answer=0;
void dfs(int cnt,int v, int sum){
    if(cnt==k){
        answer = max(sum,answer);
        return;
    }
    for(int i=v; i<n;i++){
        cout<<sum<<endl;
        dfs(cnt+1, i+1, sum+arr[i]);
    }
}

int main(){
    cin>>T;
    for(int tc=1; tc<=T;tc++){
        answer=0;
        cin>>n>>k;
        for(int i=0; i<n;i++){
            cin>>arr[i];
        }
        sort(arr,arr+n);
        int sum=0;
        for(int i=n-1; i>=n-k;i--){
            sum+=arr[i];
        }
        cout<<"#"<<tc<<" "<<sum<<'\n';
        
    }
}
