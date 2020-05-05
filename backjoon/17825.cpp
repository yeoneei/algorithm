//
//  17825.cpp
//  backjoon
//
//  Created by 조연희 on 26/03/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
int score[33]={2,4,6,8,10,12,14,16,18,20,13,
    16,19,22,24,25,22,24,26,28,30,
    28,27,26,32,34,36,38,30,35,40,0,0
};
int map[32][5]={
    {1,2,3,4,5},
    {2,3,4,5,6},{3,4,5,6,7},{4,5,6,7,8},{10,11,12,15,28},{6,7,8,9,16},
    {7,8,9,16,17},{8,9,16,17,18},{9,16,17,18,19},{13,14,15,28,29},{11,12,15,28,29},
    //11번
    {12,15,28,29,30},{15,28,29,30,31},{14,15,28,29,30},{15,28,29,30,31},{28,29,30,31,31},
    //16번
    {17,18,19,20,24},{18,19,20,24,25},{19,20,24,25,26},{20,24,25,26,27},{21,22,23,15,28},
    //21번
    {22,23,15,28,29},{23,15,28,29,30},{15,28,29,30,31},{25,26,27,30,31},{26,27,30,31,31},
    //26번
    {27,30,31,31,31},{30,31,31,31,31},{29,30,31,31,31},{30,31,31,31,31},{31,31,31,31,31},{31,31,31,31,31},
};
int arr[10];
int answer=0;
int mar[10];

int marCheck(int i, vector<int>& Mar){
    int x;
    if(Mar[mar[i]]==-1){
        x= Mar[mar[i]]+arr[i];
    }else{
        x = map[Mar[mar[i]]][arr[i]-1];
    }
    if(x>=31) return x;
    for(int i=0; i<4;i++){
        if(Mar[i]>=31) continue;
        //이거 집어 넣으면 왜 안돼지?
        if(mar[i]==i)continue;
        if(Mar[i]==x) return -1;
    }
    return x;
}

void dfs(int cnt){
    if(cnt==10){
        //Mar : 현재 말위치 mar:이번엔 어떤 말 차례인지  arr: 주사위 몇번인지
        int sum=0;
        vector<int> Mar(4,-1);
        for(int i=0; i<10;i++){
            if(Mar[mar[i]]>=31) return;
            int x = marCheck(i, Mar);
            if(x==-1) return;
            Mar[mar[i]]=x;
            if(Mar[mar[i]]>=31)continue;
            sum+=score[Mar[mar[i]]];
        }
        answer = max(answer,sum);
        return;
        
    }
    for(int i=0; i<=3;i++){
        mar[cnt]=i;
        dfs(cnt+1);
    }
}
int main(){
    for(int i=0; i<10;i++){
        cin>>arr[i];
    }
    dfs(0);
    cout<<answer;
}
