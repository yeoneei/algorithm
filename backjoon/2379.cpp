//
//  2379.cpp
//  backjoon
//
//  Created by 조연희 on 02/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int T;
char temp[2][31];

struct Tree{
    int cnt;
    vector<Tree *> children;
};

Tree* n1;
Tree* n2;

Tree* makeTree(string temp){
    if(temp[0]=='1') return nullptr;
    if(temp[0]=='0'){
        Tree *nextTree = new Tree();
        
    }
}


int main(){
    cin>>T;
    for(int i=0;i<T;i++){
        cin>>temp[0]>>temp[1];
        
    }
    
}
