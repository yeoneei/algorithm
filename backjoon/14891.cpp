//
//  14891.cpp
//  backjoon
//
//  Created by 조연희 on 02/03/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <deque>
#include <queue>
using namespace std;

deque<int> qu[4];
queue<pair<int, int>> change;
char temp;
int n,num,d;

void printfQue(){
    for(int i=0; i<4;i++){
        printf("%d th :",i);
        for(int j=0; j<qu[i].size();j++){
            printf("%d ",qu[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
int main(){
    for(int i=0; i<4;i++){
        for(int j=0; j<9;j++){
            scanf("%c",&temp);
            if(temp!='\n'){
                qu[i].push_back((int)temp-'0');
            }
        }
    }
    scanf("%d",&n);
    for(int i=0; i<n;i++){
        scanf("%d %d",&num, &d);
        num--;
        change.push(make_pair(num,d));
        int dir=d;
        //오른쪽
        for(int j=num;j<3;j++){
            if(qu[j][2]==qu[j+1][6]) break;
            change.push(make_pair(j+1, -1*dir));
            dir*=-1;
        }
        //왼쪽
        dir=d;
        for(int j=num; j>=1; j--){
            if(qu[j][6]==qu[j-1][2]) break;
            change.push(make_pair(j-1, -1*dir));
            dir*=-1;
        }
        while(!change.empty()){
            int number =change.front().first;
            int direction = change.front().second;
            change.pop();
            if(direction==1){
                int temp = qu[number].back();
                qu[number].pop_back();
                qu[number].push_front(temp);
            }
            if(direction==-1){
                int temp = qu[number].front();
                qu[number].pop_front();
                qu[number].push_back(temp);
            }
        }
    }
    int sum=0;
    if(qu[0][0]==1) sum+=1;
    if(qu[1][0]==1) sum+=2;
    if(qu[2][0]==1) sum+=4;
    if(qu[3][0]==1) sum+=8;
    cout<<sum;
}

