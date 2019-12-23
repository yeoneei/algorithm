//
//  1003.cpp
//  backjoon
//
//  Created by 조연희 on 16/07/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
int one[41]={0};
int zero[41]={0};

int main(){
    int T;
    scanf("%d",&T);
    zero[0]=1;
    one[1]=1;
    for(int i=2; i<=40;i++){
        zero[i]= zero[i-1]+zero[i-2];
        one[i]= one[i-1]+one[i-2];
    }
    
    while(T--){
        int n;
        scanf("%d",&n);
        printf("%d %d\n", zero[n],one[n]);
    }
    
    
}
