#include <iostream>
#include <queue>
#include <stdio.h>
#define MAX 14
using namespace std;
int T,n;
int map[MAX][MAX];
struct Node{
    int y;
    int x;
    Node(int y, int x):y(y),x(x){}
};
struct Cmp{
    bool operator()(Node n1, Node n2){
        if(n1.y < n2.y){
            return true;
        }else if(n1.y > n2.y){
            return false;
        }else{
            if(n1.x > n2.x){
                return true;
            }else{
                return false;
            }
        }
    }
};

queue<Node> qu;
priority_queue<Node, vector<Node>,Cmp> pq;

int checkScore(int map[][MAX]){
    int result=0;
    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            if(map[i][j]==1){
                result++;
            }
        }
    }
    return result;
}

int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

void dfs(queue<Node> qu, int map[][MAX]){
    if(qu.empty()){
        return;
    }
    
    int y = qu.front().y;
    int x = qu.front().x;
    qu.pop();
    int copy[MAX][MAX];
    for(int i=0; i<4;i++){
        for(int j=0; j<n;j++){
            for(int k=0; k<n;k++){
                copy[j][k]=map[j][k];
            }
        }
        int ny = y;
        int nx = x;
        bool check = true;
        while(1){
            ny+=dy[i];
            nx+=dx[i];
            if(ny<0 || ny>=n ||nx<0 || nx>=n){
                break;
            }
            if(copy[ny][nx] || copy[ny][nx]==2){
                check = false;
                break;
            }
            copy[ny][nx]=1;
        }
        
        if(check){
            pq.push(Node(n-(int)qu.size(),checkScore(copy)));
            dfs(qu,copy);
        }
    }
}

void init(){
    while(!qu.empty()){
        qu.pop();
    }
    while(!pq.empty()){
        pq.pop();
    }
}

int main(){
    cin>>T;
    for(int t=1; t<=T;t++){
        cin>>n;
        init();
        for(int i=0; i<n;i++){
            for(int j=0; j<n;j++){
                cin>>map[i][j];
                if(map[i][j]){
                    if(i!=0 || j!=0 || i!=n-1 || j!=n-1){
                        qu.push(Node(i,j));
                    }
                    map[i][j]=2;
                }
            }
        }
        
        dfs(qu,map);
        printf("#%d %d \n",t,pq.top().x);
        
    }
}

