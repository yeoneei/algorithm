//
//  1211.cpp
//  backjoon
//
//  Created by 조연희 on 28/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//


#include <iostream>
#include <queue>
using namespace std;

int T;
int map[200];
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cin>>T;
    for(int i=0; i<T;i++){
        cin>>map[i];
    }
    sort(map,map+T);
    cout<<map[T/2]
}
