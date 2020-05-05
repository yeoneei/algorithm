//
//  17822.cpp
//  backjoon
//
//  Created by 조연희 on 26/03/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int n,m,t;
int x,d,k;
vector<deque<int>> vc;
int tempVc[51][51];


int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void printvc(){
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            cout<<vc[i][j]<<" ";
        }
        cout<<endl;
    }
}

bool removeNumber(int y,int x){
    int value = vc[y][x];
    if(vc[y][x]==-1)return false;
    
    bool check =false;
    for(int i=0; i<4;i++){
        int nx = x+dx[i];
        int ny = y+dy[i];
        if(ny<0 || ny>=n) continue;
        if(nx<0) nx+=m;
        if(nx>=m) nx-=m;
        if(value==vc[ny][nx]){
            check=true;
            tempVc[ny][nx]= -1;
        }
    }
    
    if(!check){
        return false;
    }
    if(check) tempVc[y][x]=-1;
    return true;
}
void pastVC(){
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            tempVc[i][j]=vc[i][j];
        }
    }
}

void changeAVG(){
    int sum=0;
    int cnt=0;
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            if(tempVc[i][j]!=-1){
                sum+=tempVc[i][j];
                cnt++;
            }
        }
    }
    if(cnt==0) return;
    double avg = (double)sum/(double)cnt;
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            if(tempVc[i][j]!=-1){
                if(tempVc[i][j]>avg){
                    tempVc[i][j]--;
                }else if (tempVc[i][j]<avg){
                    tempVc[i][j]++;
                }
            }
        }
    }
}

void changeOnepan(){
    bool getAVG=false;
    pastVC();
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            if(removeNumber(i,j)){
                getAVG=true;
            }
        }
    }
    if(!getAVG) changeAVG();
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            vc[i][j]=tempVc[i][j];
        }
    }
}

int main(){
    cin>>n>>m>>t;
    vc.resize(n);
    for(int i=0; i<n;i++){
        vc[i].resize(m);
        for(int j=0; j<m;j++){
            cin>>vc[i][j];
        }
    }
    for(int i=0; i<t;i++){
        cin>>x>>d>>k;
        //0 시계방향
        //1 반시계 방향
        int idx = x;
        while(idx<=n){
            deque<int> &temp = vc[idx-1];
            for(int re=0; re<k;re++){
                if(d==0){
                    int to = temp.back();
                    temp.pop_back();
                    temp.push_front(to);
                }
                if(d==1){
                    int to = temp.front();
                    temp.pop_front();
                    temp.push_back(to);
                }
            }
            idx+=x;
        }
        changeOnepan();
    }
    
    int sum=0;
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            if(vc[i][j]!=-1){
                sum+=vc[i][j];
            }
        }
    }
    cout<<sum;
}
