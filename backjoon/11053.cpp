//
//  11053.cpp
//  backjoon
//
//  Created by 조연희 on 31/12/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
#define MAX 1000
using namespace std;

int t;
int arr[MAX+1];
int d[MAX+1];
int idx[MAX+1];
vector<int> answer;
int main(){
    cin>>t;
    int maxV=-1;
    int maxI=0;
    for(int i=0; i<t;i++){
        cin>>arr[i];
        int len=-1;
        for(int j=i-1;j>=0;j--){
            if(arr[i]>arr[j] && len<d[j]){
                len = d[j];
                idx[i]=j;
            }
        }
        if(len == -1){
            d[i]=1;
            idx[i]=-1;
        }else{
            d[i]=len+1;
        }
        if(maxV < d[i]){
            maxV = d[i];
            maxI = i;
        }
    }
    cout<<maxV<<endl;
    
    while(maxI >=0){
        answer.push_back(arr[maxI]);
        maxI = idx[maxI];
    }
    for(int i=(int)answer.size()-1;i>=0;i--){
        cout<<answer[i]<<" ";
    }
}
