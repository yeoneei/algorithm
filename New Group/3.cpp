//
//  3.cpp
//  backjoon
//
//  Created by 조연희 on 21/01/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;



int requestsServed(vector<int> timestamp, vector<int> top) {
    queue<int> qu;
    sort(timestamp.begin(),timestamp.end());
    for(int i=0; i<timestamp.size();i++){
        qu.push(timestamp[i]);
    }
    
    int cnt=0;
    for(int i=0; i<top[i];i++){
        int t=0;
        while(!qu.empty() && t<5 && qu.front()<=top[i]){
            cout<<qu.front()<<" "<<top[i]<<endl;
            qu.pop();
            t++;
            cnt++;
        }
    }
    return cnt;
}

int main(){
    vector<int> t;
    t.push_back(1);
    t.push_back(2);
    t.push_back(2);
    t.push_back(3);
    t.push_back(4);
    t.push_back(5);
    t.push_back(6);
    t.push_back(6);
    t.push_back(13);
    t.push_back(16);
    vector<int> v;
    v.push_back(10);
    v.push_back(15);
    cout<<requestsServed(t, v)<<endl;
    
    
    
    
    
    
}

