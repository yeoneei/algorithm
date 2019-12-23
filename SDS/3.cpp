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
int cnt2;
bool check= false;
int main(){
    scanf("%d",&T);
    for(int t=1;t<=T;t++){
        len=0;
        scanf("%d",&n);
        for(int i=0; i<n;i++){
            scanf("%d",&computer[i]);
            
        }
        
        for(int i=0; i<=n;i++){
            if(computer[i]==0) continue;
            cnt=0;
            for(int j=i-1;j>=0;j--){
                int temp = computer[j];
                if(temp==0){
                    cnt++;
                    len+=(i-j);
                }
                if(cnt==5){
                    break;
                }
            }
        }
        
        cnt=0;
        for(int i=n-1;i>=0;i--){
            cnt++;
            printf(" top %d ",i);
            if(computer[i]==1){
                int tempCnt=0;
                for(int j= i-1;j>=0 && tempCnt<5;j--){
                    if(computer[j]==1){
                        tempCnt=0;
                    }else{
                        tempCnt++;
                    }
                    if(tempCnt==5){
                        i=j;
                        printf(" move %d ",i);
                        break;
                    }
                }
                if(tempCnt<5){
                    printf(" temp Cnt %d",tempCnt);
                    printf(" true %d ", i);
                    break;
                    
                }
            }
        }
        
        for(int i=0; i<n;i++){
            if(computer[i]==0){
                break;
            }
            cnt++;
            printf("%d ", i);
        }
         
        printf("#%d %d %d\n",t,len,cnt);
    }
    
}
