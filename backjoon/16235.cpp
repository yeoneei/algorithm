//
//  16235.cpp
//  backjoon
//
//  Created by 조연희 on 04/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<vector<int>>> tree;
int n,m,k,x,y,z;
int nutrition[11][11];
int map[11][11];
//(r-1, c-1), (r-1, c), (r-1, c+1), (r, c-1), (r, c+1), (r+1, c-1), (r+1, c), (r+1, c+1)

int dy[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

void spring(){
    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            if(tree[i][j].size()==0)continue;
            vector<int>temp;
            int det=0;
            
            sort(tree[i][j].begin(),tree[i][j].end());
            
            
            for(int s=0; s<tree[i][j].size();s++){
                
                int age = tree[i][j][s];
                
                if(age<=map[i][j]){
                    map[i][j]-=age;
                    temp.push_back(age+1);
                }else{
                    det+= (age/2);
                }
            }
            
            tree[i][j].clear();
            
            for(int s=0; s<temp.size();s++){
                tree[i][j].push_back(temp[s]);
            }
            
            map[i][j]+=det;
            
        }
    }
}

void fall(){
    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            
            if(tree[i][j].size()==0)continue;
            
            for(int s=0; s<tree[i][j].size();s++){
                
                if(tree[i][j][s] % 5 ==0){
                    
                    for(int d =0; d<8;d++){
                        int ny = i + dy[d];
                        int nx = j + dx[d];
                        if(ny<0 || nx<0 || ny>=n || nx>=n) continue;
                        tree[ny][nx].push_back(1);
                    }
                    
                }
            }
        }
    }
}

void winter(){
    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            map[i][j]+=nutrition[i][j];
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    

    cin>>n>>m>>k;
    tree.resize(n);
    for(int i=0; i<n;i++){
        tree[i].resize(n);
        for(int j=0; j<n;j++){
            cin>>nutrition[i][j];
            map[i][j]=5;
        }
    }
    for(int i=0; i<m;i++){
        cin>>x>>y>>z;
        tree[x-1][y-1].push_back(z);
    }
    
    while(k--){
        spring();
        fall();
        winter();
    }
    
    int sum=0;
    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            sum+=tree[i][j].size();
        }
    }
    cout<<sum;
    
}
