//
//  7345.cpp
//  backjoon
//
//  Created by 조연희 on 03/07/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

struct Node{
    int cof=0;
    int ex=0;
    Node *next;
};


int main(){
    int num;
    cin>>num;
    while(num){
        num--;
        Node *first[3];
        for(int i=0; i<3;i++){
            int c;
            cin>>c;
            first[i]= new Node();
            Node * start = new Node();
            for(int j=0; j<c;j++){
                int bit;
                cin>>bit;
                Node * temp = new Node();
                temp->cof =bit;
                temp->ex = c-j-1;
            }
        }
        
    }
}
