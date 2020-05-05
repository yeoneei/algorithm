//
//  1914.cpp
//  backjoon
//
//  Created by 조연희 on 18/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

int n;

void print(int from, int to){
    cout<<from<<" "<<to<<'\n';
}
void hnoi(int n, int from, int mid, int to){
    if(n==1){
        print(from,to);
        return ;
    }
    
    hnoi(n-1,from,to,mid);
    print(from,to);
    hnoi(n-1,mid,from,to);
    
}

void getBigAnswer(){
    int arr[35]={0,};
    arr[34]=1;
    int c=0;
    int time = n;
    while(time--){
        for(int i = 34; i>=0;i--){
            arr[i]= arr[i]*2 +c;
            if(arr[i]>=10){
                arr[i]-=10;
                c=1;
            }else c=0;
        }
    }
    // 빼기 1
    arr[34]--;
    if(arr[34]<0){
        arr[34]+=10;
        int c =  -1;
        for(int i = 33; i>=0;i--){
            arr[i] = arr[i]+c;
            if(arr[i]<0){
                arr[i]+=10;
                c=-1;
            }else c=0;
        }
    }
    int idx=0;
    while(idx<35){
        if(arr[idx]==0){
            idx++;
        }else break;
    }
    
    for(int i= idx;i<35;i++){
        cout<<arr[i];
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n;
    if(n<=20){
        long long answer=1;
        for(int i=0; i<n;i++){
            answer*=2;
        }
        cout<<answer-1<<'\n';
        hnoi(n,1,2,3);
    }else{
        getBigAnswer();
    }
    
}
