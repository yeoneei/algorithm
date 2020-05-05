//
//  입국심사.cpp
//  backjoon
//
//  Created by 조연희 on 19/01/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <vector>
#include <iostream>
using namespace std;

unsigned long long solution(int n, vector<int> times) {
    unsigned long long max =0;
    unsigned long long size = times.size();
    for(int i=0; i<size;i++){
        if(times[i]>max){
            max = (long long)times[i];
        }
    }
    
    unsigned long long left=0;
    unsigned long long right=max*n;
    unsigned long long mid =0;
    unsigned long long cnt=0;
    unsigned long long result = max*n;
    while(left<=right){
        mid = (left+right)/2;
        cnt=0;
        for(int i=0; i<size;i++){
            cnt+= mid/(unsigned long long)times[i];
        }
        if(cnt < n){
            left = mid +1;
        }else{
            if(result>mid){
                result = mid;
            }
            right = mid-1;
        }
    }
    return result;
}

int main(){
    vector<int> t;
    t.push_back(6);
    t.push_back(10);
    cout<<solution(6, t)<<endl;
}
