//
//  5.cpp
//  backjoon
//
//  Created by 조연희 on 28/03/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>

#include <string>
#include <vector>

using namespace std;
int minV;
bool checkAnswer(vector<int> stones, int k, int mid){
    int cnt=0;
    for(int i=0; i<stones.size();i++){
        stones[i]-=mid-1;
        if(stones[i]<=0){
            cnt++;
            if(cnt>=k)return false;
        }
        else{
            cnt++;
            if(cnt>k) return false;
            cnt=0;
        }
    }
    return true;
}

int solution(vector<int> stones, int k) {
    int answer = 0;
    int right =0;
    int left =200000001;
    minV=left;
    for(int i=0; i<stones.size();i++){
        right = max(stones[i],right);
        left = min(stones[i],left);
    }
    answer=left;
    while(left<=right){
        int mid= (left+right)/2;
        if(!checkAnswer(stones,k,mid)){
            right = mid-1;
        }else{
            if(answer<mid){
                answer = mid;
            }
            left = mid+1;
        }
    }
    return answer;
}

int main(){
    vector<int> st ={0,0,1,0,0};
    cout<<solution(st, 3);
}
