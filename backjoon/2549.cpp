//
//  2549.cpp
//  backjoon
//
//  Created by 조연희 on 16/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int map[4][4];
int tempM[4][4];

int N;
void printMap(){
    for(int i=0; i<4;i++){
        for(int j=0; j<4;j++){
            cout<<tempM[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
vector<pair<int,int>> vc;
bool check[8];
int arr[8];
int checkNum(){
    bool check[2][4]={0,};
    
    int idx=1;
    for(int i=0; i<4;i++){
        for(int j=0; j<4;j++){
            if(map[i][j]==idx++){
                check[0][i]=true;
                check[1][j]=true;
            }
        }
    }
    int cnt=0;
    for(int i=0; i<2;i++){
        for(int j=0; j<4;j++){
            if(check[i][j]==false){
                cnt++;
                // 1-> 행 , 2-> 열
                if(i==0)vc.push_back(make_pair(1,j));
                if(i==1)vc.push_back(make_pair(2,j));
            }
        }
    }
    return cnt;
}

struct Answer{
    int c;
    int l;
    int k;
    Answer(int c, int l,int k):c(c),l(l),k(k){}
};
void calChange(int c,int k){
    while(k--){
        int temp = tempM[c][0];
        for(int i=0; i<4;i++){
            tempM[c][i] = tempM[c][i+1];
        }
        tempM[c][3]= temp;
    }
}

void rowChange(int c,int k){
    
    while(k--){
        int temp = tempM[0][c];
        for(int i=0; i<4;i++){
            tempM[i][c] = tempM[i+1][c];
        }
        tempM[3][c]= temp;
    }
}


bool checkAnswer(){
    int idx=1;
    for(int i=0;i<4;i++){
        for(int j=0; j<4;j++){
            if(tempM[i][j]!=idx)return false;
            idx++;
        }
    }
    
    return true;
}



vector<Answer> getAnswer(){
    vector<Answer> answer;
    
    for(int i=0; i<4;i++){
        for(int j=0; j<4;j++){
            tempM[i][j]=map[i][j];
        }
    }
    
    for(int i=0; i<N;i++){
        int cri = vc[arr[i]].first;
        int line = vc[arr[i]].second;
        if(cri==1){
            int x = map[line][0];
            calChange(line,4-((x-1)%4));
            answer.push_back(Answer(1,line+1,(x-1)%4));
        }
        if(cri==2){
            int x = map[0][line];
            if(x-1==0)continue;
            rowChange(line,4-((x-1)/4));
            answer.push_back(Answer(2,line+1,(x-1)/4));
            
        }
    }
    
    if(!checkAnswer()){
        answer.clear();
    }
    return answer;
}


void dfs(int cnt,int v){
    if(cnt == N){
        vector<Answer> ans = getAnswer();
        if(ans.size()==N){
            for(int i=0; i<ans.size();i++){
                cout<<ans[i].c<<" "<<ans[i].l<<" "<<ans[i].k<<endl;
            }
            exit(0);
        }
        return;
    }
    for(int i=0; i<vc.size();i++){
        if(check[i])continue;
        check[i]=1;
        arr[cnt]=i;
        dfs(cnt+1,v);
        check[i]=0;
    }
}


int main(){
    for(int i=0; i<4;i++){
        for(int j=0; j<4;j++){
            cin>>map[i][j];
        }
    }
    N = checkNum();
    if(N==8) N--;
    cout<<N<<endl;
    dfs(0,0);
    
    
    
}
