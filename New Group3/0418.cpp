//
//  0418.cpp
//  backjoon
//
//  Created by 조연희 on 18/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//


#include <iostream>
#include <deque>
using namespace std;

deque<int> map[50];
int x,d,k;
int n,m,t,temp;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void printMap(){
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            cout<<map[i][j]<<" ";
        }
        cout<<endl;
    }
}

void findInjection(){
    bool check[50][50]={0,};
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            if(map[i][j]==0)continue;
            bool cnt=false;
            for(int d=0; d<4;d++){
                int ny = i +dy[d];
                int nx = j +dx[d];
                if(ny<0)continue;
                if(ny>=n)continue;
                if(nx<0)nx+=m;
                if(nx>=m)nx-=m;
                if(check[ny][nx] || map[ny][nx]==0 || map[i][j]!=map[ny][nx])continue;
                check[ny][nx]=1;
                cnt=true;
            }
            if(cnt){
                check[i][j]=1;
            }
        }
    }
    
    int move=0;
    int sum=0;
    int cnt=0;
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            if(map[i][j]!=0){
                sum+=map[i][j];
                cnt++;
            }
            if(check[i][j]==true){
                map[i][j]=0;
                move++;
            }
        }
    }
    if(move==0){
        double value = (double)sum/(double)cnt;
        for(int i=0; i<n;i++){
            for(int j=0; j<m;j++){
                if(map[i][j]!=0){
                    if(map[i][j]>value){
                        map[i][j]--;
                        
                    }else if(map[i][j]<value){
                        map[i][j]++;
                    }
                }
            }
        }
    }
}
int main(){
    cin>>n>>m>>t;
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            cin>>temp;
            map[i].push_back(temp);
        }
    }
    for(int i=0; i<t;i++){
        cin>>x>>d>>k;
        for(int j=x; j<=n;j+=x){
            int time = k;
            while(time--){
                if(d==0){
                    int temp = map[j-1].back();
                    map[j-1].pop_back();
                    map[j-1].push_front(temp);
                }
                if(d==1){
                    int temp = map[j-1].front();
                    map[j-1].pop_front();
                    map[j-1].push_back(temp);
                }
            }
            
        }
        findInjection();
    }
    
    int sum=0;
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            sum+=map[i][j];
        }
    }
    cout<<sum;
    
    
}
