//
//  3344.cpp
//  backjoon
//
//  Created by 조연희 on 17/07/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
using namespace std;
int MAX=8;
int cols[100000];

bool promising(int level){
    for(int i=1; i<level;i++){
        int size = cols[level]-cols[i];
        if(size < 0){
            size = -1* size;
        }
        if(cols[i]==cols[level])
            return false;
        else if( size== level-i)
            return false;
    }
    return true;
}

bool queens(int level){
    if(!promising(level)){
        return false;
    }
    else if(level==MAX){
        for(int i=1;i<=MAX;i++){
            cout<<cols[i]<<endl;
        }
        return true;
    }
    else{
        for(int i=1; i<=MAX; i++){
            cols[level+1]=i;
            if(queens(level+1)){
                return true;
            }
        }
        return false;
    }
}

int main(){
    cin>>MAX;
    queens(0);
}
