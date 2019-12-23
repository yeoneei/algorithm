//
//  10256.cpp
//  backjoon
//
//  Created by 조연희 on 15/07/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
using namespace std;
int GAN[4];


int main(){
    int T;
    cin>>T;
    for(int tc=1; tc<=T;tc++){
        int n,m;
        cin>>n>>m;
        char pattern[1000001];
        char marker[101];
        scanf("%s", pattern);
        scanf("%s",marker);
        
        for(int i=0; i<m;i++){
            if(marker[i]=='A'){
                GAN[0]++;
            }else if(marker[i]=='C'){
                GAN[1]++;
            }else if(marker[i]=='G'){
                GAN[2]++;
            }else if(marker[i]=='T'){
                GAN[3]++;
            }
        }
        
        
        int temp[4]={0};
        
        for(int i=0; i<m;i++){
            if(pattern[i]=='A'){
                temp[0]++;
            }else if(pattern[i]=='C'){
                temp[1]++;
            }else if(pattern[i]=='G'){
                temp[2]++;
            }else if(pattern[i]=='T'){
                temp[3]++;
            }
        }
        int count=0;
        bool check = true;
        for(int j=0; j<4;j++){
            if(GAN[j]!=temp[j]){
                check = false;
            }
        }
        if(check== true){
            count++;
        }
        
        for(int i=m;i<n;i++){
            if(pattern[i-m]=='A'){
                temp[0]--;
            }else if(pattern[i-m]=='C'){
                temp[1]--;
            }else if(pattern[i-m]=='G'){
                temp[2]--;
            }else if(pattern[i-m]=='T'){
                temp[3]--;
            }
            
            if(pattern[i]=='A'){
                temp[0]++;
            }else if(pattern[i]=='C'){
                temp[1]++;
            }else if(pattern[i]=='G'){
                temp[2]++;
            }else if(pattern[i]=='T'){
                temp[3]++;
            }
            check = true;
            
            
            for(int j=0; j<4;j++){
                if(GAN[j]!=temp[j]){
                    check =false;
                    break;
                }
            }
            if(check == true){
                count++;
            }
            
            
        }
        
        cout<<count<<endl;
        
        
        
    }
}
