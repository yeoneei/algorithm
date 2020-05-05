//
//  1.cpp
//  backjoon
//
//  Created by 조연희 on 21/01/2020.
//  Copyright © 2020 조연희. All rights reserved.
//
#include <iostream>
#include <string>
#include <vector>
using namespace std;


/*
 * Complete the 'splitIntoTwo' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts INTEGER_ARRAY arr as parameter.
 */

int splitIntoTwo(vector<int> arr){
    long long right=0;
    for(int i=0; i<arr.size();i++){
        right+=arr[i];
    }
    int cnt=0;
    long long left=0;
    for(int i=0; i<arr.size()-1;i++){
        left +=arr[i];
        right -=arr[i];
        cout<<left<<" "<<right<<endl;
        if(left > right){
            cnt++;
        }
    }
    return cnt;
}
int main(){
    vector<int> c;
    c.push_back(10);
    c.push_back(-5);
    c.push_back(6);
    cout<<splitIntoTwo(c)<<endl;
}
