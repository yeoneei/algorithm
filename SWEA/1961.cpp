//
//  1961.cpp
//  backjoon
//
//  Created by 조연희 on 15/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int T,n;
int map[7][7];
string answer[7];


void change(){
    int temp[7][7]={0,};
    
    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            temp[i][j] = map[n-j-1][i];
        }
    }
    
    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            map[i][j]=temp[i][j];
        }
    }
}

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>T;
    for(int tc=1; tc<=T;tc++){
        cin>>n;
        for(int i=0; i<n;i++){
            for(int j=0; j<n;j++){
                cin>>map[i][j];
            }
            answer[i]="";
        }
        int t=3;
        while(t--){
            change();
            for(int i=0; i<n;i++){
                for(int j=0; j<n;j++){
                    answer[i]+=to_string(map[i][j]);
                }
                answer[i]+=" ";
            }
        }
        cout<<"#"<<tc<<" "<<'\n';
        for(int i=0; i<n;i++){
            cout<<answer[i]<<'\n';
        }
    }
    
}
