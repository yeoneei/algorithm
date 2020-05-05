//
//  12100_2.cpp
//  backjoon
//
//  Created by 조연희 on 28/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int n;
int map[20][20];
int answer=0;
void printMap(){
    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            cout<<map[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void push(int num){
    if(num==0){
    //상
        for(int i=0; i<n;i++){
            vector<int> st;
            for(int j=n-1; j>=0;j--){
                if(map[j][i]!=0){
                    st.push_back(map[j][i]);
                    map[j][i]=0;
                }
            }
            for(int j=0;j<n;j++){
                if(!st.empty()){
                    if(st.size()>=2 && st[st.size()-1]==st[st.size()-2]){
                        map[j][i]+=st.back();
                        st.pop_back();
                        map[j][i]+=st.back();
                        st.pop_back();
                        
                    }else{
                        map[j][i]=st.back();
                        st.pop_back();
                    }
                }
            }
        }
    }
    if(num==1){
        //하
        for(int i=0; i<n;i++){
            vector<int> st;
            for(int j=0; j<n;j++){
                if(map[j][i]!=0){
                    st.push_back(map[j][i]);
                    map[j][i]=0;
                }
            }
            for(int j=n-1;j>=0;j--){
                if(!st.empty()){
                    if(st.size()>=2 && st[st.size()-1]==st[st.size()-2]){
                        map[j][i]+=st.back();
                        st.pop_back();
                        map[j][i]+=st.back();
                        st.pop_back();
                    }else{
                        map[j][i]=st.back();
                        st.pop_back();
                    }
                }
            }
        }
    }
    if(num==2){
    //좌
        for(int i=0; i<n;i++){
            vector<int> st;
            for(int j=0; j<n;j++){
                if(map[i][j]!=0){
                    st.push_back(map[i][j]);
                    map[i][j]=0;
                }
            }
            for(int j=n-1;j>=0;j--){
                if(!st.empty()){
                    if(st.size()>=2 && st[st.size()-1]==st[st.size()-2]){
                        map[i][j]+=st.back();
                        st.pop_back();
                        map[i][j]+=st.back();
                        st.pop_back();
                    }else{
                        map[i][j]=st.back();
                        st.pop_back();
                    }
                }
            }
        }
        
    }
    if(num==3){
    //우
        for(int i=0; i<n;i++){
            vector<int> st;
            for(int j=n-1; j>=0;j--){
                if(map[i][j]!=0){
                    st.push_back(map[i][j]);
                    map[i][j]=0;
                }
            }
            for(int j=0;j<n;j++){
                if(!st.empty()){
                    if( st.size()>=2 &&  st[st.size()-1]==st[st.size()-2]){
                        map[i][j]+=st.back();
                        st.pop_back();
                        map[i][j]+=st.back();
                        st.pop_back();
                    }else{
                        map[i][j]=st.back();
                        st.pop_back();
                    }
                }
            }
        }
    }
}
void dfs(int cnt){
    if(cnt==10){
        for(int i=0; i<n;i++){
            for(int j=0; j<n;j++){
                answer = max(answer,map[i][j]);
            }
        }
        return ;
    }
    int temp[20][20];
    for(int i=0; i<4;i++){
        for(int y=0; y<n;y++){
            for(int x=0;x<n;x++){
                temp[y][x]=map[y][x];
            }
        }
        push(i);
        dfs(cnt+1);
        for(int y=0; y<n;y++){
            for(int x=0;x<n;x++){
                map[y][x]=temp[y][x];
            }
        }
    }
}

int main(){
    cin>>n;
    for(int i=0; i<n;i++){
        for(int j=0;j<n;j++){
            cin>>map[i][j];
        }
    }
    
    dfs(0);
    cout<<answer<<endl;
}
