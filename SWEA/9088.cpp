//
//  9088.cpp
//  backjoon
//
//  Created by 조연희 on 20/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#define MAX 10000
using namespace std;

int T,n,k,temp;
int arr[MAX+1];
int answer=0;
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cin>>T;
    for(int tc=1; tc<=T;tc++){
        cin>>n>>k;
        memset(arr,0,sizeof(arr));
        for(int i=0; i<n;i++){
            cin>>temp;
            arr[temp]++;
        }
        int sum = 0;
        int s = 1;
        int d = s+k;
        for(int i=s;i<=d;i++){
            sum+=arr[i];
        }
        answer=sum;
        d++;
        while(d<=MAX){
            sum+=arr[d];
            sum-=arr[s];
            s++;
            answer = max(answer,sum);
            d++;
        }
        cout<<"#"<<tc<<" "<<answer<<'\n';
    }
}
