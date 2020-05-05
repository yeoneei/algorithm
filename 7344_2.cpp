//
//  7344_2.cpp
//  backjoon
//
//  Created by 조연희 on 02/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int T,n,fi,se;
int main(){
    cin>>T;
    while(T--){
        cin>>n;
        priority_queue<pair<int,int>> pq;
        for(int i=0; i<n;i++){
            cin>>fi>>se;
            pq.push(make_pair(se, fi));
        }
        vector<pair<int,int>> tt;
        tt.push_back(make_pair(pq.top().first, pq.top().second));
        pq.pop();
        while(!pq.empty()){
            //second : 길이
            //first : 무게
            fi = pq.top().first;
            se = pq.top().second;
            pq.pop();
            bool check = false;
            for(int i=0; i<tt.size();i++){
                if(fi <= tt[i].first && se<=tt[i].second){
                    check = true;
                    break;
                }
            }
            if(!check){
                tt.push_back(make_pair(fi,se));
            }
        }
        cout<<tt.size()<<endl;
    }
}

