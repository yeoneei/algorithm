//
//  3074.cpp
//  backjoon
//
//  Created by 조연희 on 23/12/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

int T;
int n,m;
long long in[1000001];
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>T;
    for(int t=1;t<=T; t++){
        cin>>n>>m;
        long long max=0;
        long long left=1;
        for(int i=0; i<n;i++){
            cin>>in[i];
            if(in[i]>max){
                max = in[i];
            }
        }
        long long right = max*m;
        long long result = max*m;
        while(left <= right){
            long long mid = (left + right)/2;
            long long total = 0;
            for(int i=0; i<n;i++){
                total+=mid/in[i];
            }
            if(total<m){
                left = mid+1;
            }else{
                if(result>mid){
                    result=mid;
                }
                right = mid-1;
            }
        }
        cout<<'#'<<t<<' '<<result<<'\n';
    }
}
