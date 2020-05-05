//
//  17143.cpp
//  backjoon
//
//  Created by 조연희 on 10/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;

int cc=0;
struct Node{
    int y;
    int x;
    int d;
    int s;
    int z;
    Node(){}
    Node(int y,int x, int s, int d, int z):y(y),x(x),s(s),d(d),z(z){
    }
};

int dy[4]={-1,1,0,0};
int dx[4]={0,0,1,-1};

int chageDir(int d){
    if(d== 0)return 1;
    if(d==1)return 0;
    if(d==2)return 3;
    return 2;
}
vector<Node> vc;
int n,m,x,y,s,d,z,k;
int map[100][100];
int idx=-1;

void printMap(){
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            cout<<map[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
bool CMP(Node n1, Node n2){
    if(abs(idx-n1.x)< abs(idx-n2.x))return true;
    else if(abs(idx-n1.x)> abs(idx-n2.x))return false;
    else{
        if(n1.y < n2.y)return true;
    }
    return false;
}

int getNode(){
    sort(vc.begin(),vc.end(),CMP);
    int z=0;
    if(vc[0].x == idx){
        z = vc[0].z;
        vc.erase(vc.begin());
    }
    return z;
}

bool base(int n1, int n2){
    return n1>n2;
}
void changeLocation(){
    memset(map, 0, sizeof(map));
    vector<int> removeNum;
    for(int i=0; i<vc.size();i++){
        int y = vc[i].y;
        int x = vc[i].x;
        int s = vc[i].s;
        int d = vc[i].d;
        int z = vc[i].z;
        
        if(d==0 || d==1){
            s%=2*(n-1);
        }
        
        if(d==2 || d==3){
            s%=2*(m-1);
        }
        
        while(s--){
            y +=dy[d];
            x +=dx[d];
            if(y<0 || y>=n || x<0 || x>=m){
                d = chageDir(d);
                y+=dy[d]*2;
                x+=dx[d]*2;
            }
        }
        
        if(map[y][x]!=0){
            if(vc[map[y][x]-1].z<z){
                removeNum.push_back(map[y][x]);
                map[y][x]=i+1;
            }else{
                removeNum.push_back(i+1);
            }
        }else{
            map[y][x]=i+1;
        }
        vc[i].y = y;
        vc[i].x = x;
        vc[i].d = d;
    }
    if(!removeNum.empty()){
        sort(removeNum.begin(),removeNum.end(),base);
        
        for(int i=0; i<removeNum.size();i++){
            vc.erase(vc.begin()+removeNum[i]-1);
        }
    }
    
}

int main(){
    cin>>n>>m>>k;
    if(k==0){
        cout<<0;
        return 0;
    }
    for(int i=0; i<k;i++){
        cin>>y>>x>>s>>d>>z;
        vc.push_back(Node(y-1,x-1,s,d-1,z));
        map[y-1][x-1]=i+1;
    }
    
    int sum=0;
    while(idx<m){
        idx++;
        sum+=getNode();
        changeLocation();
    }
    cout<<sum<<endl;
}
