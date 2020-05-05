//
//  4615.cpp
//  backjoon
//
//  Created by 조연희 on 15/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <string.h>
using namespace std;

int T,n,m;
char map[50][50];
int num[50][3];
int arr[2];
int ans;
void dfs(int cnt,int v){
    if(cnt==2){
        int sum = 0;
        for(int i=0; i<arr[0];i++){
            sum+=num[i][1]+num[i][2];
        }
        for(int i=arr[0];i<=arr[1];i++){
            sum+=num[i][0]+num[i][1];
        }
        for(int i=arr[1]+1; i<n; i++){
            sum+=num[i][0]+num[i][2];
        }
        
        if(ans>sum){
            ans= sum;
        }
        return ;
    }
    for(int i=v; i<n-1;i++){
        arr[cnt]=i;
        dfs(cnt+1,i);
    }
}
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>T;
    for(int tc=1; tc<=T;tc++){
        memset(num,0,sizeof(num));
        ans= 60*60;
        cin>>n>>m;
        for(int i=0; i<n;i++){
            for(int j=0; j<m;j++){
                cin>>map[i][j];
                switch (map[i][j]) {
                    case 'W':
                        num[i][0]++;
                        break;
                    case 'R':
                        num[i][1]++;
                        break;
                    case'B':
                        num[i][2]++;
                        break;
                }
            }
        }
        dfs(0,1);
        cout<<'#'<<tc<<" "<<ans<<'\n';
    }
}
