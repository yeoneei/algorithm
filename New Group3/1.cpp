//
//  1.cpp
//  backjoon
//
//  Created by 조연희 on 29/03/2020.
//  Copyright © 2020 조연희. All rights reserved.
//
// you can use includes, for example:
// #include <algorithm>

// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
#include <iostream>
#include <vector>
using namespace std;

int arr[1000000001];
int maxV;
int cnt;
int solution(vector<int> &A){
    // write your code in C++14 (g++ 6.2.0)
    for(int i=0; i<A.size();i++){
        arr[A[i]]++;
    }
    maxV=0;
    for(int i=0; i<A.size();i++){
        if(A[i]!=arr[A[i]])continue;
        if(cnt < arr[A[i]]){
            cnt = arr[A[i]];
            maxV = A[i];
        }
    }
    return maxV;
}

int main(){
    vector<int> test = {5, 5, 5, 5, 5};
    cout<<solution(test);
}
