//
//  66.cpp
//  backjoon
//
//  Created by 조연희 on 25/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

vector<int> input;

int score[33]={0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,22,24,28,27,26,19,16,13,25,30,35,40,0};

int map[33][5]={
    {1,2,3,4,5},
    {2,3,4,5,6},
    {3,4,5,6,7},
    {4,5,6,7,8},
    {5,6,7,8,9},
    {27,26,25,28,29},
    {7,8,9,10,11},
    {8,9,10,11,12},
    {9,10,11,12,13},
    {10,11,12,13,14},
    {20,21,28,29,30},
    {12,13,14,15,16},
    {13,14,15,16,17},
    {14,15,16,17,18},
    {15,16,17,18,19},
    {22,23,24,28,29},
    {17,18,19,31,32},
    {18,19,31,32,32},
    {19,31,32,32,32},
    {31,32,32,32,32},
    {21,28,29,30,31},
    {28,29,30,31,32},
    {23,24,28,29,30},
    {24,28,29,30,31},
    {28,29,30,31,32},
    {28,29,30,31,32},
    {25,28,29,30,31},
    {26,25,28,29,30},
    {29,30,31,32,32},
    {30,31,32,32,32},
    {31,32,32,32,32},
    {32,32,32,32,32},
    {32,32,32,32,32}
};

int marIdx[10];
int answer=0;

void getScore(){
    int mar[4]={0,};
    int ans=0;
    bool check[33]={0,};
    bool ansCheck=false;
    for(int i=0; i<10;i++){
       //이동할 말
        int idx = marIdx[i];
        if(mar[idx]==32)continue;
        //이동할 번호
        int changeIdx = map[mar[idx]][input[i]-1];
        if(changeIdx==32){
            check[mar[idx]]=0;
            mar[idx]=32;
            continue;
        }
        if(check[changeIdx]==1){
            ansCheck=true;
            break;
        }
        check[mar[idx]]=0;
        mar[idx]=changeIdx;
        check[mar[idx]]=1;
        ans +=score[mar[idx]];
    }
    if(ansCheck)return;
    answer = max(ans,answer);
    
}
void dfs(int cnt){
    if(cnt==10){
        getScore();
        return;
    }
    for(int i=0; i<4;i++){
        marIdx[cnt]=i;
        dfs(cnt+1);
    }
}



int main(){
    input.resize(10);
    for(int i=0; i<10;i++){
        cin>>input[i];
    }
    dfs(0);
    cout<<answer<<endl;
}
