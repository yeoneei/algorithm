//
//  11286.cpp
//  backjoon
//
//  Created by 조연희 on 05/03/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

struct Node{
    int realn;
    int n;
};

int nodeCnt=0;
Node nodes[100001];
void insertNode(int n){
    nodes[++nodeCnt].realn=n;
    nodes[nodeCnt].n = (n<0?-1*n:n);
    
    int parent = nodeCnt/2;
    int child = nodeCnt;
    
    while(child>1 && nodes[parent].n >= nodes[child].n){
        if(nodes[parent].n == nodes[child].n && nodes[parent].realn < nodes[child].realn) break;
        swap(nodes[parent],nodes[child]);
        child = parent;
        parent = child/2;
    }
}

int deleteNode(){
    if(nodeCnt==0) return 0;
    int answer = nodes[1].realn;
    nodes[1]= nodes[nodeCnt--];
    int here = 1;
    int child = here*2;
    if(child+1 <= nodeCnt){
        child = nodes[child].n>nodes[child+1].n? child+1:child;
        if(nodes[child].n == nodes[child+1].n){
            child = nodes[child].realn>nodes[child+1].realn?child+1:child;
        }
    }
    while(child<=nodeCnt && nodes[here].n >= nodes[child].n){
        if(nodes[here].n == nodes[child].n && nodes[here].realn < nodes[child].realn) break;
        swap(nodes[here],nodes[child]);
        here = child;
        child = here*2;
        if(child+1 <= nodeCnt){
            child = nodes[child].n>nodes[child+1].n? child+1:child;
            if(nodes[child].n == nodes[child+1].n){
                child = nodes[child].realn>nodes[child+1].realn?child+1:child;
            }
        }
    }
    return answer;
}

int n,temp;
int main(){
    cin>>n;
    for(int i=0; i<n;i++){
        cin>>temp;
        if(temp==0){
            cout<<deleteNode()<<'\n';
        }else{
            insertNode(temp);
        }
    }
}
