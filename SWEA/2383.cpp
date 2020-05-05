//
//  2383.cpp
//  backjoon
//
//  Created by 조연희 on 29/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int T,n;
int map[10][10];
vector<pair<int,int>> p;
vector<pair<int,int>> d;

int arr[10];
int answer=10000;

void dfs(int cnt){
    if(cnt==p.size()){
        vector<int> vc[2];
        for(int i=0; i<p.size();i++){
            int type = arr[i];
            vc[type].push_back(abs(p[i].first - d[type].first)+abs(p[i].second-d[type].second));
        }
        sort(vc[0].begin(),vc[0].end());
        sort(vc[1].begin(),vc[1].end());
        cout<<map[d[0].first][d[0].second]<<endl;
        for(int i=0; i<vc[0].size();i++){
            cout<<vc[0][i]<<" ";
        }
        cout<<endl;
        
        cout<<map[d[1].first][d[1].second]<<endl;
        for(int i=0; i<vc[1].size();i++){
            cout<<vc[1][i]<<" ";
        }
        cout<<endl;
        deque<int> de;
        int now = 0;
        for(int i=0; i<vc[0].size();i++){
            if(de.size()<3){
                if(now<=vc[0][i]){
                    de.push_back(vc[0][i]+map[d[0].first][d[0].second]+1);
                }else de.push_back(now+map[d[0].first][d[0].second]+1);
            }else{
                now = de.front();
                de.pop_front();
                if(now<=vc[0][i]){
                    de.push_back(vc[0][i]+map[d[0].first][d[0].second]+1);
                }else de.push_back(now+map[d[0].first][d[0].second]);
            }
        }
        int semiAnswr=100000;
        if(de.size()!=0){
            semiAnswr = de.back();
        }
        de.clear();
        now= 0;
        for(int i=0; i<vc[1].size();i++){
            if(de.size()<3){
                if(now<=vc[1][i]){
                    de.push_back(vc[1][i]+map[d[1].first][d[1].second]+1);
                }else de.push_back(now+map[d[1].first][d[1].second]+1);
            }else{
                now = de.front();
                de.pop_front();
                if(now<=vc[1][i]){
                    de.push_back(vc[1][i]+map[d[1].first][d[1].second]+1);
                }else de.push_back(now+map[d[1].first][d[1].second]);
            }
        }
        if(semiAnswr==100000){
            semiAnswr = de.back();
        }else if(semiAnswr!=100000 && de.size()!=0){
            semiAnswr = max(de.back(),semiAnswr);
        }
        cout<<semiAnswr<<endl;
        answer = min(answer,semiAnswr);
        
        return;
    }
    
    for(int i=0; i<d.size();i++){
        arr[cnt]=i;
        dfs(cnt+1);
    }
}

int main(){
    cin>>T;
    for(int tc=1; tc<=T;tc++){
        cin>>n;
        p.clear();
        d.clear();
        answer=10000000;
        for(int i=0; i<n;i++){
            for(int j=0; j<n;j++){
                cin>>map[i][j];
                if(map[i][j]==1){
                    p.push_back(make_pair(i,j));
                }
                if(map[i][j]>=2){
                    d.push_back(make_pair(i,j));
                }
            }
        }
        dfs(0);
        cout<<answer<<endl;
        
    }
}
