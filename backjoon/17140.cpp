//
//  17140.cpp
//  backjoon
//
//  Created by 조연희 on 06/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int r,c,k;
int rCnt=3;
int cCnt=3;
int ms[100][100];

void printMap(){
    for(int i=0 ; i<rCnt;i++){
        for(int j=0; j<cCnt;j++){
            cout<<ms[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

bool Cmp(pair<int,int> p1, pair<int,int>p2){
    if(p1.second < p2.second) return true;
    else if(p1.second > p2.second)return false;
    else {
        return p1.first < p2.first;
    }
}

void Roperation(){
    for(int i=0 ;i<rCnt;i++){
        map<int,int> m;
        vector<pair<int, int>>vc;
        for(int j=0; j<cCnt;j++){
            if(ms[i][j]==0)continue;
            m[ms[i][j]]++;
            ms[i][j]=0;
        }
        
        map<int,int>::iterator iter = m.begin();
        for(;iter!= m.end();iter++){
            vc.push_back(make_pair(iter->first, iter->second));
        }
        sort(vc.begin(),vc.end(),Cmp);
        int idx=0;
        for(int j=0; j<vc.size();j++){
            if(j>=50)break;
            ms[i][idx++]=vc[j].first;
            ms[i][idx++]=vc[j].second;
        }
        cCnt = max(idx, cCnt);
    }
}

void Coperation(){
    for(int i=0 ;i<cCnt;i++){
        map<int,int> m;
        vector<pair<int, int>>vc;
        for(int j=0; j<rCnt;j++){
            if(ms[j][i]==0)continue;
            m[ms[j][i]]++;
            ms[j][i]=0;
        }
        
        map<int,int>::iterator iter = m.begin();
        for(;iter!= m.end();iter++){
            vc.push_back(make_pair(iter->first, iter->second));
        }
        sort(vc.begin(),vc.end(),Cmp);
        int idx=0;
        for(int j=0; j<vc.size();j++){
            if(j>=50)break;
            ms[idx++][i]=vc[j].first;
            ms[idx++][i]=vc[j].second;
        }
        rCnt = max(idx, rCnt);
    }
}




int main(){
    cin>>r>>c>>k;
    for(int i=0; i<3;i++){
        for(int j=0; j<3;j++){
            cin>>ms[i][j];
        }
    }
    int t=0;
    r--;c--;
    bool com =false;
    while(t<=100){
        if(ms[r][c]==k){
            com=true;
            break;
        }
        if(rCnt >=cCnt){
            Roperation();
        }else Coperation();
        
        t++;
    }
    if(!com)cout<<-1;
    else cout<<t;
}
