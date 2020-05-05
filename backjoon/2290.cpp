//
//  2290.cpp
//  backjoon
//
//  Created by 조연희 on 12/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

char map[23][180];
int t;
int startIdx=0;
string str;

void printmap(){
    for(int i=0; i<2*t+3;i++){
        for(int j=0; j<startIdx-1;j++){
            cout<<map[i][j];
        }
        cout<<endl;
    }
}
int main(){
    cin>>t;
    cin>>str;
    for(int i=0;i<2*t+3;i++){
        for(int j=0; j<2*t*str.size()+20;j++){
            map[i][j]=' ';
        }
    }
    startIdx=0;
    for(int i=0; i<str.size();i++){
        if(str[i]=='1'){
            for(int i=0; i<t;i++){
                map[1+i][startIdx+t+1]='|';
                map[2*t+1-i][startIdx+t+1]='|';
            }
            startIdx+=t+2;
        }else if(str[i]=='2'){
            for(int i=0; i<t;i++){
                map[0][startIdx+1+i]='-';
                map[((2*t+3)/2)][startIdx+1+i]='-';
                map[2*t+2][startIdx+1+i]='-';
                map[1+i][startIdx+t+1]='|';
                map[2*t+1-i][startIdx]='|';
            }
            startIdx+=t+2;
        }else if(str[i]=='3'){
            for(int i=0; i<t;i++){
                map[0][startIdx+1+i]='-';
                map[((2*t+3)/2)][startIdx+1+i]='-';
                map[2*t+2][startIdx+1+i]='-';
                map[1+i][startIdx+t+1]='|';
                map[2*t+1-i][startIdx+t+1]='|';
            }
            startIdx+=t+2;
            
        }else if(str[i]=='4'){
            for(int i=0; i<t;i++){
                map[((2*t+3)/2)][startIdx+1+i]='-';
                map[1+i][startIdx]='|';
                map[1+i][startIdx+t+1]='|';
                map[2*t+1-i][startIdx+t+1]='|';
            }
            startIdx+=t+2;
        }else if(str[i]=='5'){
            for(int i=0; i<t;i++){
                map[0][startIdx+1+i]='-';
                map[((2*t+3)/2)][startIdx+1+i]='-';
                map[2*t+2][startIdx+1+i]='-';
                map[1+i][startIdx]='|';
                map[2*t+1-i][startIdx+t+1]='|';
            }
            startIdx+=t+2;
        }else if(str[i]=='6'){
            for(int i=0; i<t;i++){
                map[0][startIdx+1+i]='-';
                map[((2*t+3)/2)][startIdx+1+i]='-';
                map[2*t+2][startIdx+1+i]='-';
                map[1+i][startIdx]='|';
                map[2*t+1-i][startIdx+t+1]='|';
                map[2*t+1-i][startIdx]='|';
            }
            startIdx+=t+2;
        }else if(str[i]=='7'){
            for(int i=0; i<t;i++){
                map[0][startIdx+1+i]='-';
                map[1+i][startIdx+t+1]='|';
                map[2*t+1-i][startIdx+t+1]='|';
            }
            startIdx+=t+2;
        }else if(str[i]=='8'){
            for(int i=0; i<t;i++){
                map[0][startIdx+1+i]='-';
                map[((2*t+3)/2)][startIdx+1+i]='-';
                map[2*t+2][startIdx+1+i]='-';
                map[1+i][startIdx]='|';
                map[1+i][startIdx+t+1]='|';
                map[2*t+1-i][startIdx+t+1]='|';
                map[2*t+1-i][startIdx]='|';
            }
            startIdx+=t+2;
        }else if(str[i]=='9'){
            for(int i=0; i<t;i++){
                map[0][startIdx+1+i]='-';
                map[((2*t+3)/2)][startIdx+1+i]='-';
                map[2*t+2][startIdx+1+i]='-';
                map[1+i][startIdx]='|';
                map[1+i][startIdx+t+1]='|';
                map[2*t+1-i][startIdx+t+1]='|';
            }
            startIdx+=t+2;
        }else if(str[i]=='0'){
            for(int i=0; i<t;i++){
                map[0][startIdx+1+i]='-';
                map[2*t+2][startIdx+1+i]='-';
                map[1+i][startIdx]='|';
                map[1+i][startIdx+t+1]='|';
                map[2*t+1-i][startIdx+t+1]='|';
                map[2*t+1-i][startIdx]='|';
            }
            startIdx+=t+2;
        }
        startIdx++;
    }
    printmap();
    
}
