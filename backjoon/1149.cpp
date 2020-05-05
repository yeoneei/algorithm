//
//  1149.cpp
//  backjoon
//
//  Created by 조연희 on 02/01/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
using namespace std;
int n;
int house[1001][3];
int main(){
    cin>>n;
    for(int i=0; i<n;i++){
        for(int j=0; j<3;j++){
            cin>>house[i][j];
        }
    }
    
    
    for(int i=1; i<n;i++){
        house[i][0] += min(house[i-1][1],house[i-1][2]);
        house[i][1] += min(house[i-1][0],house[i-1][2]);
        house[i][2] += min(house[i-1][0],house[i-1][1]);
    }
    int min=house[n-1][0];
    for(int i=0; i<3;i++){
        if(min > house[n-1][i]){
            min = house[n-1][i];
        }
    }
    cout<<min<<endl;
}
