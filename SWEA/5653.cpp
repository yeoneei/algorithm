//
//  5653.cpp
//  backjoon
//
//  Created by 조연희 on 14/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int map[350][350];
int active[350][350];
int check[350][350];

struct Node{
    int y;
    int x;
    int ac;
    Node(int y, int x, int ac):y(y),x(x),ac(ac){}
};

int T,n,m,k,temp;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>T;
    for(int t=1; t<=T;t++){
        cin>>n>>m>>k;
        cout<<"#"<<t<<" ";
        for(int i=0; i<350;i++){
            for(int j=0; j<350;j++){
                //1 이상 : 활성화, -1:비활성화 , -2 :쥬금
                active[i][j]=-2;
                check[i][j]=-1;
                map[i][j]=0;
            }
        }
        queue<Node> qu;
        for(int i=0; i<n;i++){
            for(int j=0; j<m;j++){
                cin>>temp;
                if(temp!=0){
                    qu.push(Node(150+i,150+j,0));
                    map[150+i][150+j]=temp;
                    active[150+i][150+j]=temp;
                    check[150+i][150+j]=0;
                }
                
            }
        }
        int time=0;
        while(k--){
            int s = (int)qu.size();
            while(s--){
                if(active[qu.front().y][qu.front().x]>0){
                    active[qu.front().y][qu.front().x]--;
                    qu.push(Node(qu.front().y,qu.front().x,qu.front().ac));
                    qu.pop();
                    continue;
                }
                int y = qu.front().y;
                int x = qu.front().x;
                int ac = qu.front().ac;
                qu.pop();
                if(active[y][x]==-1){
                    ac--;
                    if(map[y][x]==-1*ac){
                        active[y][x]=-2;
                        continue;
                    }
                    qu.push(Node(y,x,ac));
                    continue;
                }
               
                for(int i=0;i<4;i++){
                    int ny = y +dy[i];
                    int nx = x +dx[i];
                    if(check[ny][nx]!=-1 && check[ny][nx]<time+1)continue;
                    if(check[ny][nx]==-1){
                        map[ny][nx]=map[y][x];
                        active[ny][nx]=map[y][x];
                        check[ny][nx]=time+1;
                        qu.push(Node(ny,nx,0));
                    }
                    if(check[ny][nx]!=-1 && map[y][x]>map[ny][nx]){
                        map[ny][nx]=map[y][x];
                        active[ny][nx]=map[y][x];
                    }
                }
                if(map[y][x]==1){
                    active[y][x]=-2;
                }else{
                    active[y][x]=-1;
                    qu.push(Node(y,x,-1));
                }
            }
            time++;
        }
        int cnt=0;
        for(int i=0; i<350;i++){
            for(int j=0; j<350;j++){
                if(active[i][j]!=-2)cnt++;
            }
        }
        cout<<cnt<<endl;
    }
}
