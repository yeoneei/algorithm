#include <iostream>
using namespace std;

int n,m,h,a,b;
bool map[32][12];
bool answer=false;
int answerNum=3;
bool checkAnswer(){
    for(int i=1; i<=n;i++){
        int start =i;
        for(int j=1; j<=h;j++){
            if(map[j][start]==1)start++;
            else if(start>1 && map[j][start-1]==1) start--;
        }
        if(start!=i)return false;
    }
    return true;
}

void dfs(int cnt, int y){
    if(cnt<=3){
        if(checkAnswer()){
            answer=true;
            if(answerNum>cnt){
                answerNum = cnt;
            }
        }
    }
    if(cnt==3)return;
    for(int i=y;i<=h;i++){
        for(int j=1;j<=n;j++){
            if(map[i][j]==1 || map[i][j-1]==1 || map[i][j+1]==1)continue;
            map[i][j]=1;
            dfs(cnt+1,i);
            map[i][j]=0;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m>>h;
    for(int i=0; i<m;i++){
        cin>>a>>b;
        map[a][b]=1;
    }
    dfs(0,1);
    if(answer){
        cout<<answerNum;
    }else{
        cout<<-1;
    }
}
