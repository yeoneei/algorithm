//
//  2178_2.cpp
//  backjoon
//
//  Created by 조연희 on 29/05/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
int map [101][101];
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
int Y, X;
int countSize=0;
struct Node{
    int x;
    int y;
};
