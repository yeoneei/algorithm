//
//  33.cpp
//  backjoon
//
//  Created by 조연희 on 02/05/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int map[100][100];
int rowCnt;
int colCnt;
int r,c,k;

struct Node{
    int num;
    int cnt;
    Node(int num, int cnt):num(num),cnt(cnt){}
};

struct CMP{
    bool operator()(Node n1, Node n2){
        if(n1.cnt < n2.cnt)return false;
        if(n1.cnt > n2.cnt)return true;
        else{
            if(n1.num < n2.num)return false;
            else return true;
        }
    }
};

void rowChagne(){
    int colMAx=0;
    for(int i=0; i<rowCnt;i++){
        int cnt[101]={0,};
        for(int j=0; j<100;j++){
            cnt[map[i][j]]++;
            map[i][j]=0;
        }
        priority_queue<Node, vector<Node>,CMP>pq;
        for(int i=1; i<=100;i++){
            if(cnt[i]==0)continue;
            pq.push(Node(i,cnt[i]));
        }
        int idx=0;
        while(!pq.empty()){
            map[i][idx++]=pq.top().num;
            map[i][idx++]=pq.top().cnt;
            pq.pop();
        }
        colMAx = max(idx,colMAx);
    }
    colCnt = colMAx;
}
void colChagne(){
    int rowMAx=0;
    for(int i=0; i<colCnt;i++){
        int cnt[101]={0,};
        for(int j=0; j<100;j++){
            cnt[map[j][i]]++;
            map[j][i]=0;
        }
        priority_queue<Node, vector<Node>,CMP>pq;
        for(int i=1; i<=100;i++){
            if(cnt[i]==0)continue;
            pq.push(Node(i,cnt[i]));
        }
        int idx=0;
        while(!pq.empty()){
            map[idx++][i]=pq.top().num;
            map[idx++][i]=pq.top().cnt;
            pq.pop();
        }
        rowMAx = max(idx,rowMAx);
    }
    rowCnt=rowMAx;
}

void printMap(){
    cout<<rowCnt<<" "<<colCnt<<endl;
    for(int i=0; i<rowCnt;i++){
        for(int j=0; j<colCnt;j++){
            cout<<map[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}


int main(){
    cin>>r>>c>>k;
    int t=0;
    for(int i=0; i<3;i++){
        for(int j=0; j<3;j++){
            cin>>map[i][j];
        }
    }
    r--;c--;
    rowCnt=3;
    colCnt=3;
    while(t<=100){
        if(map[r][c]==k)break;
        if(rowCnt>=colCnt) rowChagne();
        else colChagne();
        t++;
    }
    
    if(t<=100) cout<<t;
    else cout<<-1;
}
