//
//  1045.cpp
//  backjoon
//
//  Created by 조연희 on 27/03/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <queue>
#include <string.h>
#define MAX 50
using namespace std;

int n,m;
char t;
struct Node{
    int y;
    int x;
    Node(int y, int x):y(y),x(x){}
};
int parent[MAX];
int arr[MAX];
queue<Node> qu;

int find(int x){
    if(parent[x]==x){
        return x;
    }
    return parent[x]=find(parent[x]);
}

bool uion(int y, int x){
    x = find(x);
    y = find(y);
    
    if(x==y)return false;
    if(x<y){
        parent[y]=x;
    }else{
        parent[x]=y;
    }
    return true;
}

bool checkMST(){
    int value = find(0);
    for(int i=0; i<n;i++){
        if(value!=find(i)) return false;
    }
    return true;
}

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n>>m;
    for(int i=0; i<n;i++){
        parent[i]=i;
        for(int j=0; j<n;j++){
            cin>>t;
            if(t=='Y' && i<j){
                qu.push(Node(i,j));
            }
        }
    }
    
    if(qu.size()<m){
        cout<<-1;
        return 0;
    }
    
    queue<Node> elseNode;
    int cnt=0;
    
    while(!qu.empty()){
        if(checkMST()){
            break;
        }
        int y = qu.front().y;
        int x = qu.front().x;
        qu.pop();
        if(!uion(y,x)){
            elseNode.push(Node(y,x));
            continue;
        }
        cnt++;
        arr[y]++;
        arr[x]++;
    }
    
    if(!checkMST()){
        cout<<-1;
        return 0;
    }
    if(cnt<m){
        while(!elseNode.empty()){
            if(cnt>=m)break;
            arr[elseNode.front().y]++;
            arr[elseNode.front().x]++;
            elseNode.pop();
            cnt++;
        }
        while(!qu.empty()){
            if(cnt>=m)break;
            arr[qu.front().y]++;
            arr[qu.front().x]++;
            qu.pop();
            cnt++;
        }
    }
    
    for(int i=0; i<n;i++){
        cout<<arr[i]<<" ";
    }
}
