//
//  3197.cpp
//  backjoon
//
//  Created by 조연희 on 07/12/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

int l,p,v;
int main(){
    int i=1;
    while(1){
        cin>>l>>p>>v;
        if(l==0 && p==0 && v==0){
            return 0;
        }
        int day = (v/p)*l;
        day += ((v%p)-l>0?l:(v%p));
        cout<<"Case "<<i<<":"<<" "<<day<<endl;
        i++;
    }
}
