//
//  17281.cpp
//  backjoon
//
//  Created by 조연희 on 29/03/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int n;
vector<vector<int>> vc;
int play[9];
bool check[9];
int answer=0;
void getScore(){
    int ening=0,j=0,scroe=0;
    while(ening<n){
        int out=0;
        deque<int> de;
        while(out<3){
            int now = vc[ening][play[j]];
            if(now==0){
                out++;
            } else if(now==1 ||now==2 || now==3){
                for(int s=0; s<de.size();s++){
                    de[s]+=now;
                }
                while(!de.empty() && de[0]>3){
                    scroe++;
                    de.pop_front();
                }
                de.push_back(now);
            }else if(now==4){
                scroe+=(de.size()+1);
                de.clear();
            }
            j++;
            if(j==9){
                j=0;
            }
            
        }
        ening++;
    }
    answer = max(scroe,answer);
}
void getPlayer(int cnt){
    if(cnt==9){
        getScore();
        return;
    }
    for(int i=1; i<9;i++){
        if(check[i])continue;
        check[i]=1;
        play[cnt]=i;
        if(cnt+1==3){
            getPlayer(cnt+2);
        }else getPlayer(cnt+1);
        check[i]=0;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    vc.resize(n);
    for(int i=0; i<n;i++){
        vc[i].resize(9);
        for(int j=0; j<9;j++){
            cin>>vc[i][j];
        }
    }
    play[3]=0;
    check[0]=1;
    getPlayer(0);
    cout<<answer;
}
