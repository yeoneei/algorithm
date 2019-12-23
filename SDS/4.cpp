//
//  3.cpp
//  backjoon
//
//  Created by 조연희 on 22/12/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <stdio.h>
#define MAX 200000

int T;
int n;
int len;
int computer[MAX];
int cnt;
int cloudCnt;
int main(){
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        len=0;
        scanf("%d",&n);
        cloudCnt=0;
        bool start = false;
        for(int i=0; i<n;i++){
            scanf("%d",&computer[i]);
            if(!start && computer[i]){
                cloudCnt++;
            }
            if(!start && !computer[i]){
                start = true;
            }
            
        }
        
        bool lenCheck=false;
        int lenCnt=0;
        int idx=n-1;
        
        bool cloudCheck = false;
        bool check = false;
        bool last = true;
        for(int i=n-1;i>=0;i--){
            if(idx==i){
                last = false;
            }
            if(computer[i]==0){
                if(check==false && !last) {
                    cloudCnt++;
                }
                continue;
            }
            
            lenCheck=false;
            lenCnt=0;
            int tempCnt=0;
            if(check==false && cloudCheck==true){
                tempCnt=5;
            }
            if(check==false && cloudCheck==true && idx==i){
                cloudCheck=false;
            }
            
            for(int j=i-1; j>=0;j--){
                if(lenCheck && cloudCheck){
                    break;
                }
                
                if(check ==false && cloudCheck ==false && computer[j]==1){
                    tempCnt=0;
                }
                if(check==false && cloudCheck==false && computer[j]==0){
                    tempCnt++;
                }
                if(check==false && cloudCheck==false && tempCnt==5){
                    idx=j-1;
                    last = true;
                    cloudCheck=true;
                }
                if(lenCheck==false && computer[j]==0){
                    lenCnt++;
                    len+=(i-j);
                }
                if(lenCheck==false && lenCnt==5){
                    lenCheck=true;
                }
            }
            
            if(check==false && tempCnt<5){
                cloudCnt++;
                check=true;
            }
        }
        printf("#%d %d %d\n",t,len,cloudCnt);
    }
    
}
