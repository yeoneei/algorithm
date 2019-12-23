//
//  11943.cpp
//  backjoon
//
//  Created by 조연희 on 15/08/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;
struct Cordi{
    int x;
    int y;
};
Cordi liCordi[100000];
bool sortDei(Cordi a, Cordi b){
    return (a.y!=b.y?a.y<b.y:a.x<b.x);
}
int n;
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>n;
    for(int i=0; i<n;i++){
        cin>>liCordi[i].x >>liCordi[i].y;
    }
    sort(liCordi,liCordi+n,sortDei);
    for(int i=0; i<n;i++){
        cout<<liCordi[i].x<<" "<<liCordi[i].y<<endl;
    }
}
