
//
//  2578.cpp
//  backjoon
//
//  Created by 조연희 on 28/12/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#define MAX 5
using namespace std;
int map[MAX][MAX];
int n = 25;

void insertInt(int n){
    for(int i=0; i<MAX;i++){
        for(int j=0; j<MAX;j++){
            if(n == map[i][j]){
                map[i][j]=-1;
                return;
            }
        }
    }
}

bool checkBingo(){
    //가로체크
    int check=0;
    for(int i=0; i<MAX;i++){
        if(map[i][0]==-1 && map[i][1]==-1 && map[i][2]==-1 && map[i][3]==-1 && map[i][4]==-1){
            check++;
        }
    }
    //세로체크
    for(int i=0; i<MAX;i++){
        if(map[0][i]==-1 && map[1][i]==-1 && map[2][i]==-1 && map[3][i]==-1 && map[4][i]==-1){
            check++;
        }
    }
    //대각선
    if(map[0][0]==-1 && map[1][1]==-1 && map[2][2]==-1 && map[3][3]==-1 && map[4][4]==-1){
        check++;
    }
    
    if(map[0][4]==-1 && map[1][3]==-1 && map[2][2]==-1 && map[3][1]==-1 && map[4][0]==-1){
        check++;
    }
    return check>=3;
}


int main(){
    for(int i=0; i<MAX;i++){
        for(int j=0; j<MAX;j++){
            cin>>map[i][j];
        }
    }
    int temp=0;
    while(n--){
        cin>>temp;
        insertInt(temp);
    
        if(checkBingo()){
            cout<<25-n;
            return 0;
        }
        
    }
}
