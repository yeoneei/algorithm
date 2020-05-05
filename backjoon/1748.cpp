//
//  1748.cpp
//  backjoon
//
//  Created by 조연희 on 24/03/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

int n;
int arr[9]={9,99,999,9999,99999,999999,9999999,99999999,999999999};
int size[9]={1,2,3,4,5,6,7,8,9};
int main(){
    cin>>n;
    if(n<10){
        cout<<n;
        return 0;
    }
    
    int idx = 1;
    long long answer=9;
    while(idx<9){
        if(n > arr[idx]){
            answer += (arr[idx]-arr[idx-1])*size[idx];
        }else if( n <=arr[idx]){
            answer += (n - arr[idx-1])*size[idx];
            break;
        }
        idx++;
    }
    if(n > arr[8]){
        answer+=  (n-arr[8])+2;
    }
    cout<<answer;
}
