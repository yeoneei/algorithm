#include <iostream>
using namespace std;
int n;
int map[1000][1000];
void dfs(int v){
    cout<<v+1<<" ";
    for(int i=0; i<n;i++){
        map[v][i]--;
        map[i][v]--;
        dfs(i);
    }
    
    
}
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    int cnt=0;
    bool returnCheck=false;
    for(int i=0; i<n;i++){
        cnt=0;
        for(int j=0; j<n;j++){
            cin>>map[i][j];
            if(map[i][j]==1){
                cnt+=map[i][j];
            }
        }
        if(cnt%2==1){
            returnCheck=true;
        }
    }
    
    if(returnCheck){
        cout<<"-1"<<endl;
    }else{
        dfs(0);
    }
}
