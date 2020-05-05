//
//  15658.cpp
//  backjoon
//
//  Created by 조연희 on 12/03/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int oper[4];
int number[12];
int operat[11];
int n;
vector<int> ans;

void dfs(int cnt){
    if(cnt==n-1){
        int answer =number[0];
        for(int i=0; i<cnt;i++){
            switch (operat[i]) {
                case 0:
                    answer += number[i+1];
                    break;
                case 1:
                    answer-=number[i+1];
                    break;
                case 2:
                    answer *=number[i+1];
                    break;
                case 3:
                    answer /=number[i+1];
            }
        }
        ans.push_back(answer);
        return;
    }
    
    for(int i=0; i<4;i++){
        if(oper[i]==0)continue;
        oper[i]--;
        operat[cnt]=i;
        dfs(cnt+1);
        oper[i]++;
    }
}



int main(){
    cin>>n;
    for(int i=0; i<n;i++){
        cin>>number[i];
    }
    for(int i=0; i<4;i++){
        cin>>oper[i];
    }
    dfs(0);
    sort(ans.begin(),ans.end());
    cout<<ans[ans.size()-1]<<'\n';
    cout<<ans[0]<<'\n';
}
