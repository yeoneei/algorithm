//
//  2512.cpp
//  backjoon
//
//  Created by 조연희 on 13/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> input;
int sum;
int main(){
    cin>>n;
    int r=0;
    input.resize(n);
    for(int i=0; i<n;i++){
        cin>>input[i];
        r = max(r,input[i]);
    }
    cin>>sum;
    int l=1;
    int answer = l;
    while(l<=r){
        int mid = (l+r)/2;
        int temp=0;
        for(int i=0; i<n;i++){
            temp += (input[i]>mid?mid:input[i]);
        }
        if(temp>sum){
            r = mid-1;
        }
        if(temp<=sum){
            answer = max(answer,mid);
            l = mid+1;
        }
    }
    cout<<answer;
    
}
