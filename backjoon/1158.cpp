//
//  1158.cpp
//  backjoon
//
//  Created by 조연희 on 27/11/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

struct Node{
    int n;
    Node * next;
    Node(int n):n(n){}
};

int n,k;
int con=0;

int main(){
    cin>>n>>k;
    con=n;
    Node *start = (Node*)malloc(sizeof(Node));
    Node *current = start;
    for(int i=0; i<n;i++){
        Node* newOne = (Node *)malloc(sizeof(Node));
        newOne->n = (i+1);
        current->next = newOne;
        current = current->next;
    }
    current->next = start->next;
    cout<<"<";
    current = start;
    Node* pre;
    while(con!=0){
        for(int i=0; i<k-1;i++){
            current = current->next;
        }
        pre = current;
        current = current->next;
        cout<<current->n;
        pre->next = current->next;
        con--;
        if(con>0){
            cout<<", ";
        }
    }
    cout<<">"<<endl;
}
