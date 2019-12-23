//
//  2858.cpp
//  backjoon
//
//  Created by 조연희 on 19/08/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int sum=0;
    for(int i=0; i<5;i++){
        int temp;
        cin>>temp;
        sum+=pow(temp,2);
    }
    cout<<sum%10<<endl;
}
