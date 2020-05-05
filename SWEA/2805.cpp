//
//  2805.cpp
//  backjoon
//
//  Created by 조연희 on 30/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

int T,n;
char charMap[49][49];
int map[49][49];

bool check[49][49];
int main(){
    cin>>T;
    for(int tc=1; tc<=T;tc++){
        cin>>n;
        for(int i=0; i<n;i++){
            for(int j=0; j<n;j++){
                cin>>charMap[i][j];
                map[i][j]=(int)(charMap[i][j]-'0');
            }
        }
        
        int sum=0;
        for(int i=0; i<=(n/2);i++){
            for(int j = (n/2)-i ; j<=(n/2)+i;j++){
                sum+=map[i][j];
            }
        }
        for(int i= (n/2)+1; i<n;i++){
            for(int j = (n/2)-(n-i-1);j<=(n/2)+(n-i-1);j++){
                sum+=map[i][j];
            }
        }
        cout<<"#"<<tc<<" "<<sum<<'\n';
    }
}
