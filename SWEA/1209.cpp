//
//  1209.cpp
//  backjoon
//
//  Created by 조연희 on 19/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
using namespace std;
int map[100][100];
int sum=0,n;
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    for(int tc=1; tc<=10;tc++){
        sum=0;
        cin>>n;
        for(int i=0; i<100;i++){
            int temp=0;
            for(int j=0;j<100;j++){
                cin>>map[i][j];
                temp+=map[i][j];
            }
            sum = max(temp,sum);
        }
    
        int temp=0;
        int t1=0;
        int t2=0;
        for(int i=0; i<100;i++){
            temp=0;
            t1 += map[i][i];
            t2 += map[i][99-i];
            for(int j=0; j<100;j++){
                temp+=map[j][i];
            }
            sum = max(temp,sum);
        }
        sum = max(t1,sum);
        sum = max(t2,sum);
        cout<<"#"<<tc<<" "<<sum<<'\n';
    }
}
