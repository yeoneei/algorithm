//
//  1240.cpp
//  backjoon
//
//  Created by 조연희 on 18/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

int T,n,m;
char map[50][100];
int startIdxI=0;
int startIdxJ=0;
int arr[100];
int answer[8];
bool first=false;
int cri[10][4]={
    {3,2,1,1},
    {2,2,2,1},
    {2,1,2,2},
    {1,4,1,1},
    {1,1,3,2},
    {1,2,3,1},
    {1,1,1,4},
    {1,3,1,2},
    {1,2,1,3},
    {3,1,1,2}
};

int main(){
    freopen("/Users/yeoni/Desktop/test/backjoon/SWEA/input.txt", "r", stdin);
    cin>>T;
    for(int tc=1; tc<=T;tc++){
        startIdxI=0;
        startIdxJ=0;
        first =false;
        cin>>n>>m;
        for(int i=0; i<n;i++){
            for(int j=0; j<m;j++){
                cin>>map[i][j];
                if(!first && map[i][j]=='1'){
                    startIdxI=i;
                    startIdxJ=j;
                    first=true;
                }
            }
        }
        int idx=0;
        int cnt=1;
        for(int i=startIdxJ+1; i<m;i++){
            if(map[startIdxI][i]==map[startIdxI][i-1]){
                cnt++;
            }else{
                arr[idx++]=cnt;
                cnt=1;
            }
        }
        int ansIdx=0;
        for(int i=0; i<10;i++){
            if(cri[i][1]==arr[0] && cri[i][2]==arr[1] && cri[i][3]==arr[2]){
                answer[ansIdx++]=i;
                break;
            }
        }
        for(int j=3;j<=idx;j+=4){
            for(int i=0; i<10;i++){
                if(cri[i][0] == arr[j] && cri[i][1]==arr[j+1] && cri[i][2]==arr[j+2] && cri[i][3]==arr[j+3]){
                    answer[ansIdx++]=i;
                    break;
                }
            }
        }
        int test = (answer[0]+answer[2]+answer[4]+answer[6])*3 + answer[1]+answer[3]+answer[5]+answer[7];
        cout<<'#'<<tc<<" ";
        if(test%10 ==0){
            int sum=0;
            for(int i=0; i<8;i++){
                sum+=answer[i];
            }
            cout<<sum<<'\n';
        }else{
            cout<<0<<'\n';
        }
        
    }
}
