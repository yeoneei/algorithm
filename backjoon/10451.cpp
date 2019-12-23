//
//  10451.cpp
//  backjoon
//
//  Created by 조연희 on 08/04/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

bool check[1001]={0};
int input[1001];

void dfs(int j, int &count,int startNum){
    if(check[j]==true && j==startNum){
        count=count+1;
        return;
    }
    if(j != startNum && check[j]==true) return;
    check[j]=true;
    dfs(input[j],count, startNum);
}

int main(){
    int n;
    cin>>n;
    
    for(int i=0; i<n; i++){
        int num;
        cin>>num;
        for(int j=1; j<=num;j++){
            cin>>input[j];
        }
        int count=0;
        for(int j=1; j<=num;j++){
            if(check[j]==false) dfs(j,count,j);
        }
        
        cout<<count<<endl;
        for(int j=1; j<=num;j++){
            input[j]=0;
            check[j]=0;
        }
        
    }
}
