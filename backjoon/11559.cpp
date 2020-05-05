#include <iostream>
#include <queue>
#include <stack>
#include <string.h>
using namespace std;


char map[12][6];
bool check[12][6];

struct Node{
    int y;
    int x;
    Node(int y, int x):y(y),x(x){}
};


int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};

int dfs(int y, int x, char ch){
    
    int ret =1;
    for(int i=0; i<4;i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(ny<0 || ny>=12 || nx<0 || nx>=6 ||check[ny][nx])continue;
        if(map[ny][nx]==ch){
            check[ny][nx]=1;
            ret +=dfs(ny,nx,ch);
        }
    }
    return ret;
}


queue<pair<int,int>> qu;
bool endCheck(){
    memset(check,0,sizeof(check));
    for(int i=0; i<12;i++){
        for(int j=0; j<6;j++){
            if(map[i][j]=='.' || check[i][j]==1)continue;
            check[i][j]=1;
            int cnt = dfs(i,j,map[i][j]);
            if(cnt>=4){
                qu.push(make_pair(i,j));
            }
        }
    }
    
    if(qu.empty())return false;
    return true;
}
void remove(int y, int x, char ch){
    for(int i=0; i<4;i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(ny<0 || ny>=12 || nx<0 || nx>=6 )continue;
        
        if(map[ny][nx]==ch){
            map[ny][nx]='.';
            remove(ny,nx,ch);
        }
    }
    
}
stack<char> st;

void printMap(){
    for(int i=0; i<12;i++){
        for(int j=0; j<6;j++){
            cout<<map[i][j]<<" ";
        }
        cout<<endl;
    }
}
void getMap(){
    for(int x=0; x<6;x++){
        for(int y=0; y<12;y++){
            if(map[y][x]=='.')continue;
            st.push(map[y][x]);
            map[y][x]='.';
        }
        for(int y=11;y>=0;y--){
            if(!st.empty()){
                map[y][x]=st.top();
                st.pop();
            }else break;
        }
    }
}


int main(){
    for(int i=0; i<12;i++){
        for(int j=0; j<6;j++){
            cin>>map[i][j];
        }
    }
    int answer=0;
    while(endCheck()){
        answer++;
        while(!qu.empty()){
            remove(qu.front().first,qu.front().second, map[qu.front().first][qu.front().second]);
            map[qu.front().first][qu.front().second]='.';
            qu.pop();
            getMap();
        }
    }
    cout<<answer<<endl;
}
