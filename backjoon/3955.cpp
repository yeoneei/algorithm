//
//  3955.cpp
//  backjoon
//
//  Created by 조연희 on 09/01/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <string>
#define MAX 1000000
using namespace std;

string a;
bool p[MAX+3];
int size;
bool go(int x) {
    int ret = 0;
    for (int i = 0; a[i]; i++) {
        ret *= 10;
        ret += (a[i] - '0');
        ret %= x;
    }
    return ret == 0;
}
int k;
int main(){
    cin>>a>>k;
    for(int i=2;i*i<=k;i++){
        if(p[i]==1)continue;
        for(int j=i+i; j<=k;j+=i){
            p[j]=1;
        }
    }
    for(int i=2;i<k;i++){
        if(p[i]==1) continue;
        if(go(i)){
            printf("BAD %d",i);
            return 0;
        }
    }
    printf("GOOD");
}
