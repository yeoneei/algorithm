//
//  2098.cpp
//  backjoon
//
//  Created by 조연희 on 14/08/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

const int MAX =16;
const int INF = 987654321;
int N;
int w[MAX][MAX];
int cache[MAX][1 << MAX];

int TSP(int here, int visited){
    if(visited == (1<<N)-1){
        if(w[here][0]!=0){
            return w[here][0];
        }
        return INF;
    }
    int &result = cache[here][visited];
    if(result!=-1){
        return result;
    }
    result = INF;
    for(int next=0;next<N;next++){
        if (visited & (1 << next) || w[here][next]==0)
            continue;
        int candidate = w[here][next] + TSP(next, visited + (1 << next));
        
        result = min(result, candidate);
    }
    return result;
}

int main(void)

{
    
    cin>>N;
    if(N<2 || N>MAX) return 0;
    
    for(int i=0; i<N;i++)
        for(int j=0; j<N;j++)
            cin>>w[i][j];
    
    memset(cache,-1,sizeof(cache));
    cout << TSP(0, 1) << endl;
    return 0;
}

