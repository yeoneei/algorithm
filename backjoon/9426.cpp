//
//  9426.cpp
//  backjoon
//
//  Created by 조연희 on 15/03/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n,k,temp;
vector<int> input;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>k;
    input.resize(n);
    for(int i=0; i<n;i++){
        cin>>input[i];
    }
    int cnt = n-k+1;
    int start=0;
    int end=k;
    long long answer=0;
    while(cnt){
        priority_queue<int,vector<int>,less<int>> l;
        priority_queue<int,vector<int>,greater<int>> r;
        for(int i=start;i<end;i++){
            temp = input[i];
            if(!r.empty() &&temp > r.top()){
                r.push(temp);
                if(l.size() < r.size()){l.push(r.top());r.pop();}
            }else{
                l.push(temp);
                if(l.size() > r.size()+1){r.push(l.top());l.pop();}
            }
        }
        answer+=l.top();
        start++;
        end++;
        cnt--;
    }
    cout<<answer;
}
