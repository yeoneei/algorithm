//
//  16224.cpp
//  backjoon
//
//  Created by 조연희 on 29/07/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

struct Node{
    int x;
    int y;
    int z;
    Node(){}
    Node(int x, int y, int z): x(x),y(y),z(z){}
};

int dx[6] = {0,0,1,-1,0,0};
int dy[6] = {1,-1,0,0,0,0};
int dz[6] = {0,0,0,0,1,-1};

queue<Node> nodeQ;
int map[100][100][100];
int n,m,h;
int countA;


//안익은게 있는지 확인
bool checkMap(){
    bool check = false;
    for(int k=0; k<h;k++){
        if(check) break;
        for(int i =0; i<n;i++){
            if(check) break;
            for(int j=0; j<m;j++){
                if(map[k][i][j]==0){
                    check = true;
                }
            }
        }
    }
    return check;
}

void bfs(){
    if(nodeQ.empty()==true) return;
    
    while(!nodeQ.empty()){
        if(checkMap()==false) return;
        int size = (int)nodeQ.size();
        for(int i=0; i<size;i++){
            Node temp = nodeQ.front();
            nodeQ.pop();
            for(int j=0; j<6;j++){
                Node newNode;
                newNode.x = temp.x + dx[j];
                newNode.y = temp.y + dy[j];
                newNode.z = temp.z + dz[j];
                if(0<= newNode.x  && newNode.x <m && 0<=newNode.y && newNode.y<n
                   && 0<=newNode.z && newNode.z<h && map[newNode.z][newNode.y][newNode.x]==0){
                    map[newNode.z][newNode.y][newNode.x]=1;
                    nodeQ.push(newNode);
                }
            }
        }
        
        countA++;
    }
}
int main(){
    cin>>m>>n>>h;
    for(int k=0; k<h;k++){
        for(int i =0; i<n;i++){
            for(int j=0; j<m;j++){
                cin>>map[k][i][j];
                if(map[k][i][j]==1){
                    Node temp{j,i,k};
                    nodeQ.push(temp);
                }
            }
        }
    }
    

    bfs();
    if(checkMap()==true){
        cout<<-1<<endl;
    }
    else{
        cout<<countA<<endl;
    }
    
}


