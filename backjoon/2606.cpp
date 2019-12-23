//
//  2606.cpp
//  backjoon
//
//  Created by 조연희 on 08/04/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool computer[101]={false};
bool match[101][101]={false};
struct L{
    int first;
    int second;
};

void bfs(queue<int> &node, int n){

    while(!node.empty()){
        int x = node.front();
        node.pop();
        if(!computer[x]){
            computer[x]=true;
            for(int i=1;i<=n;i++){
                if(match[x][i]==true){
                    node.push(i);
                }
            }
        }
    }
}

int main(){
    int n;
    cin>>n;
    int pa;
    cin>>pa;
    for(int i=0; i<pa;i++){
        int u,v;
        cin>>u>>v;
        match[u][v]=match[v][u]=1;
    }
    queue<int> node;
    node.push(1);
    bfs(node,n);
    
    int cnt=0;
    for(int i=1; i<=n;i++){
        if(computer[i]){
            cnt++;
        }
    }
    cout<<cnt-1<<endl;
}
