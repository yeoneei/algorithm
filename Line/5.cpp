//
//  5.cpp
//  backjoon
//
//  Created by 조연희 on 01/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

long long combi[25][25];
int n,m,y,x;
int main(){
    for(int i=0; i<25;i++){
        combi[i][0]=1;
        combi[i][i]=1;
    }
    
    for(int i=1; i<25;i++){
        for(int j=1;j<25;j++){
            combi[i][j]=combi[i-1][j-1]+combi[i-1][j];
        }
    }
    cin>>n>>m;
    cin>>y>>x;
    cout<<y+x<<endl;
    cout<<combi[y+x][y];
    
}
