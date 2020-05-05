//
//  11653.cpp
//  backjoon
//
//  Created by 조연희 on 09/01/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <cmath>
using namespace std;
const int SIZE = 10000000;
bool arr[10000001] = {0,};
int n;
int main() {
    for (int i = 2; i*i < SIZE; i++) {
        if (arr[i] != true) {
            for (int j = i * i; j < SIZE; j += i) {
                arr[j] = true;
            }
        }
    }
    scanf("%d", &n);
    for(int i=2; i<SIZE;i++){
        if(arr[i]!=true && n%i==0){
            printf("%d \n",i);
            n/=i;i--;
            continue;
        }
    }
    
}
