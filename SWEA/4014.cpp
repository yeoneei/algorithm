//
//  4014.cpp
//  backjoon
//
//  Created by 조연희 on 18/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//
#include <iostream>
using namespace std;

int T,n,m;
int map[20][20];


bool checkCol(int c){
    int cnt=1;
    for(int i=0; i<n-1;i++){
        if(map[c][i]==map[c][i+1]){
            cnt++;
        }else{
            if(map[c][i]-map[c][i+1] == 1){
                int s =0;
                if(i+m>=n)return false;
                for(int j=i+1; j<i+1+m;j++){
                    if(map[c][i+1]==map[c][j]){
                        s++;
                    }else break;
                }
                if(s!=m) return false;
                else{
                    i=i+m-1;
                    
                }
                cnt=0;
                continue;
            }else if(map[c][i]-map[c][i+1] == -1){
                if(cnt<m)return false;
                cnt=1;
            }else return false;
        }
    }
    
    if(map[c][n-2]-map[c][n-1]==1){
        return false;
    }
    return true;
}

bool checkRow(int c){
    int cnt=1;
    for(int i=0; i<n-1;i++){
        if(map[i][c]==map[i+1][c]){
            cnt++;
        }else{
            if(map[i][c]-map[i+1][c] == 1){
                int s =0;
                if(i+m>=n)return false;
                for(int j=i+1; j<i+1+m;j++){
                    if(map[i+1][c]==map[j][c]){
                        s++;
                    }else break;
                }
                if(s!=m) return false;
                else{
                    i=i+m-1;
                    
                }
                cnt=0;
                continue;
            }else if(map[i][c]-map[i+1][c] == -1){
                if(cnt<m)return false;
                cnt=1;
            }else return false;
        }
    }
    
    if(map[n-2][c]-map[n-1][c]==1){
        return false;
    }
    return true;
}


int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cin>>T;
    for(int tc=1; tc<=T;tc++){
        cin>>n>>m;
        for(int i=0; i<n;i++){
            for(int j=0; j<n;j++){
                cin>>map[i][j];
            }
        }
        
        int count=0;
        for(int i=0; i<n;i++){
            if(checkCol(i)){
                count++;
            }
            
            if(checkRow(i)){
                count++;
            }
            
        }
        cout<<"#"<<tc<<" "<<count<<'\n';
        
    }
}
