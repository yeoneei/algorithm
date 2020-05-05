//
//  5639.cpp
//  backjoon
//
//  Created by 조연희 on 25/02/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

struct Node{
    int value;
    Node *right;
    Node *left;
    Node():right(NULL),left(NULL){}
    Node(int value):value(value),right(NULL),left(NULL){}
};
Node * root;

void post(Node *temp){
    if(temp->left !=NULL){
        post(temp->left);
    }
    if(temp->right != NULL){
        post(temp->right);
    }
    cout<<temp->value<<'\n';
    return;
}
void insert(Node *temp,int v){
    if(temp->value > v){
        if(temp->left == NULL){
            Node* newNode = new Node(v);
            temp->left = newNode;
            return;
        }else{
            insert(temp->left,v);
            return;
        }
    }else{
        if(temp->right==NULL){
            Node* newNode = new Node(v);
            temp->right = newNode;
            return;
        }else{
            insert(temp->right, v);
            return;
        }
    }
    return;
}

int v;
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>v;
    root = new Node(v);
    while(cin>>v){
        insert(root,v);
    }
    post(root);
    
}
