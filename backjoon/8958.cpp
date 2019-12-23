//
//  8958.cpp
//  backjoon
//
//  Created by 조연희 on 26/03/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int main(){
    int n;
    cin>>n;
    cin.ignore();
    for(int i=0; i<n;i++){
        string a;
        getline(cin, a);
        
        int sum=0;
        int score=0;
        for(int j=0;j<a.size();j++){
            if(a.at(j)=='O'){
                score++;
                sum+=score;
            }
            if(a.at(j)=='X'){
                
                score=0;
            }
        }
        cout<<sum<<endl;
    }
    
}
