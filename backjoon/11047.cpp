//
//  11047.cpp
//  backjoon
//
//  Created by 조연희 on 22/03/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(int a, int b){
    return a>b;
}

int main()
{
    int num, price;
    vector<int> coin;
    
    cin>>num>>price;
    for(int i=0; i<num;i++){
        int a;
        cin>>a;
        coin.push_back(a);
    }
    
    sort(coin.begin(),coin.end(),compare);
    
    int count=0,i=0;
    while(price){
        int dif = price - coin.at(i);
        if(dif<0) i++;
        else {
            price-=coin.at(i);
            count++;
        }
    }
    
    cout<<count<<endl;
    
}
