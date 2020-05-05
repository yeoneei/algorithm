//
//  14503.cpp
//  backjoon
//
//  Created by 조연희 on 26/02/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int n,m,r,c,d;
int map[50][50];
struct Node{
    int y;
    int x;
    int d;
    Node(int y,int x, int d):y(y),x(x),d(d){}
};
int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};
queue<Node> qu;

void printMap(){
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            cout<<map[i][j]<<" ";
        }
        cout<<'\n';
    }
    cout<<'\n';
}

int turnLeft(int d){
    d--;
    if(d<0)return d+4;
    return d;
}

int main(){
    
    cin>>n>>m;
    cin>>r>>c>>d;
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            cin>>map[i][j];
        }
    }
    int clean=1;
    map[r][c]=2;
    qu.push(Node(r,c,d));
    while(1){
        int y = qu.front().y;
        int x = qu.front().x;
        int d = qu.front().d;
        int origin = d;
        qu.pop();
        bool check=false;
        for(int i=0; i<4;i++){
            d = turnLeft(d);
            int ny = y+dy[d];
            int nx = x+dx[d];
            if(ny<0 || ny>=n || nx<0 || nx>=m|| map[ny][nx]==1 || map[ny][nx]==2)continue;
            map[ny][nx]=2;
            clean++;
            check = true;
            qu.push(Node(ny,nx,d));
            break;
        }
        if(!check){
            int ny = y - dy[origin];
            int nx = x - dx[origin];
            if(ny<0 || ny>=n || nx<0 || nx>=m|| map[ny][nx]==1) break;
            if(map[ny][nx]!=2){
                map[ny][nx]=2;
                clean++;
            }
            qu.push(Node(ny,nx,d));
        }
        printMap();
    }
    
    cout<<clean;
}

/*
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 50;

typedef struct
{
    int y, x;
}Dir;

Dir moveDir[4] = { {-1, 0}, {0, 1}, {1, 0}, {0, -1} }; // N E S W

int N, M;
int graph[MAX][MAX];
void printMap(){
    for(int i=0; i<N;i++){
        for(int j=0; j<M;j++){
            cout<<graph[i][j]<<" ";
        }
        cout<<'\n';
    }
    cout<<'\n';
    
}
int main(void)
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N >> M;
    
    int r, c, d;
    cin >> r >> c >> d;
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> graph[i][j];
    
    int result = 0;
    queue<pair<pair<int, int>, int>> q;
    q.push({ {r, c}, d });
    
    while (!q.empty())
    {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int dir = q.front().second;
        if (graph[y][x] == 0)
        {
            //벽과 구분 위해
            graph[y][x] = 2;
            result++;
        }
        q.pop();
        
        bool flag = false;
        for (int i = 0; i < 4; i++)
        {
            //좌회전을 위해 모듈러 연산
            int nextDir = (dir + (3 - i)) % 4;
            int nextY = y + moveDir[nextDir].y;
            int nextX = x + moveDir[nextDir].x;
            
            if(0<=nextY && nextY < N && 0 <= nextX && nextX < M)
                if (!graph[nextY][nextX])
                {
                    q.push({ {nextY, nextX}, nextDir});
                    flag = true;
                    break;
                }
        }
        
        //네 방향 다 청소되어 있는 경우
        if (!flag)
        {
            int beforeY = y - moveDir[dir].y;
            int beforeX = x - moveDir[dir].x;
            if ((0 <= beforeY && beforeY < N && 0 <= beforeX && beforeX < M) && graph[beforeY][beforeX] != 1)
                q.push({ {beforeY, beforeX}, dir });
            else
                break;
        }
        printMap();
    }
    
    cout << result << "\n";
    return 0;
}
*/
