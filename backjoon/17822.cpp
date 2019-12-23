//
//  17822.cpp
//  backjoon
//
//  Created by 조연희 on 07/12/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#define MAX 50;
using namespace std;

int n,m,k;
int x,d,t;

struct Node{
    int n;
    Node *pre;
    Node *Next;
    Node(int n):n(n){}
    Node(){};
};
Node *head[50];
int main(){
    cin>>n>>m>>k;
    Node *current = new Node();
    for(int i=0; i<n;i++){
        head[i] = new Node();
        current = head[i];
        for(int j=0; j<m;j++){
            int key;
            cin>>key;
            Node *newOne = new Node(key);
            newOne->pre = current;
            current->Next = newOne;
            current = newOne;
        }
        current->Next = head[i]->Next;
        head[i]->Next->pre = current;
    }
    
    for(int i=0; i<k;i++){
        cin>>x>>d>>t;
        Node *current = head[i]->Next;
        if(d==0){
            for(int i=0; i<t;i++){
                current = current->pre;
            }
        }else{
            for(int i=0; i<t;i++){
                current = current->Next;
            }
        }
        head[i]->Next = current;
    }
    
    
    
    
}
