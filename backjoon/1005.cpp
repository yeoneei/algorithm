//
//  1005.cpp
//  backjoon
//
//  Created by 조연희 on 30/03/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int T;
int n,m,a,b,k;
int ti[1001];
int result[1001];
int line[1001];
vector<vector<int>> vc;
int main(){
    cin>>T;
    for(int t=0; t<T;t++){
        vc.clear();
        cin>>n>>m;
        for(int i=1; i<=n;i++){
            cin>>ti[i];
            result[i]=0;
            line[i]=0;
        }
        vc.resize(n+1);
        for(int i=0; i<m;i++){
            cin>>a>>b;
            vc[a].push_back(b);
            line[b]++;
        }
        
        
        cin>>k;
        queue<int> qu;
        for(int i=1; i<=n;i++){
            if(line[i]==0){
                result[i]=ti[i];
                qu.push(i);
            }
        }
        while(!qu.empty()){
            int s = qu.front();
            qu.pop();
            if(s==k)break;
            for(int next :vc[s]){
                result[next] = max(result[s]+ti[next],result[next]);
                --line[next];
                if(line[next]==0){
                    qu.push(next);
                }
            }
        }
        cout<<result[k]<<'\n';
    }
}
