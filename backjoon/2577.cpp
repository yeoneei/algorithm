//
//  2577.cpp
//  backjoon
//
//  Created by 조연희 on 26/03/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

int arr[10]={0};

int main(){
    int a,b,c;
    cin>>a;
    cin>>b;
    cin>>c;
    int result = a*b*c;
    
    int ten =10;
    while(1){
        arr[(result%10)]++;
        result/=ten;
        if(result==0){
            break;
        }
    }
    
    for(int i=0; i<10;i++){
        cout<<arr[i]<<endl;
    }
}
