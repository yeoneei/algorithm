//
//  16940.cpp
//  backjoon
//
//  Created by 조연희 on 19/02/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

vector<vector<int>> map;
int n,s,d;
vector<int> result;
queue<int> qu;

int main(){
    cin>>n;
    map.resize(n+1);
    for(int i=0; i<n-1;i++){
        cin>>s>>d;
        map[s].push_back(d);
        map[d].push_back(s);
    }
    result.resize(n);
    for(int i=0; i<n;i++){
        cin>>result[i];
    }
    
    qu.push(result[0]);
    int idx=0;
    while(!qu.empty()){
        int  x  = qu.front();
        qu.pop();
        int cnt=0;
        for(int i=idx+1; i<= idx+map[x].size();i++){
            int v = result[i];
            bool ch = false;
            for(int value : map[x]){
                if(v == value){
                    ch =true;
                    cnt++;
                    break;
                }
            }
            if(!ch){
                cout<<0;
                return 0;
            }
        }
        if(cnt != map[x].size()){
            cout<<0;
            return 0;
        }
        idx +=map[x].size();
    }
    cout<<1;
    
}
