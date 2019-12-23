//
//  2902.cpp
//  backjoon
//
//  Created by 조연희 on 28/07/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
using namespace std;
char name[101];

int strLen(char * arr){
    int i=0;
    while(arr[i]!=0) i++;
    return i;
}

int main(){
    cin>>name;
    int size = strLen(name);
    for(int i=0; i<size; i++){
        if(name[i]<='Z' && name[i]>='A'){
            cout<<name[i];
        }
    }
}
