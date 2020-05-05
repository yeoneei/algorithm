//
//  15654.cpp
//  backjoon
//
//  Created by 조연희 on 12/03/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,temp,m;
vector<int> input;
int printNumber[10];
bool number[10];
void dfs(int cnt){
    if(cnt == m){
        for(int i=0; i<m;i++){
            cout<<printNumber[i]<<' ';
        }
        cout<<'\n';
    }
    for(int i=0; i<input.size();i++){
        if(number[i])continue;
        number[i]=1;
        printNumber[cnt]=input[i];
        dfs(cnt+1);
        number[i]=0;
    }
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n;i++){
        cin>>temp;
        input.push_back(temp);
    }
    sort(input.begin(),input.end());
    dfs(0);
}
