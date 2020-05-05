//
//  14391.cpp
//  backjoon
//
//  Created by 조연희 on 18/02/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
using namespace std;
int n,m;
int map[4][4];
int main(){
    scanf("%d %d",&n,&m);
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            scanf("%1d",&map[i][j]);
        }
    }
    int answer=0;
    for(int s=0; s< (1<<(n*m)) ;s++){
        int sum=0;
        for(int i=0; i<n;i++){
            int cur=0;
            for(int j=0; j<m;j++){
                int k = i*m+j;
                if((s&(1<<k))==0){
                    cur = cur*10 + map[i][j];
                }else{
                    sum+=cur;
                    cur=0;
                }
            }
            sum+=cur;
        }
        for(int j=0; j<m;j++){
            int cur=0;
            for(int i=0; i<n;i++){
                int k = i*m+j;
                if((s& (1<<k))!=0){
                    cur = cur*10 +map[i][j];
                }else{
                    sum+=cur;
                    cur=0;
                }
            }
            sum+=cur;
        }
        
        answer = max(sum, answer);
    }
    cout<<answer;

    
}
