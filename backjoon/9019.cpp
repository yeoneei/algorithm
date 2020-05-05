//
//  9019.cpp
//  backjoon
//
//  Created by 조연희 on 28/03/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <queue>
#include <string>
using namespace std;

int T,a,b;
struct Node{
    int num;
    string str;
    Node(int num, string str):num(num),str(str){}
};
queue<Node> qu;

int leftShift(int number){
    string st = to_string(number);
    if(st.size()!=4){
        for(int i=0; i<4-st.size();i++){
            st = "0"+st;
        }
    }
    string temp="";
    for(int i=1;i<4;i++){
        temp+=st[i];
    }
    temp+=st[0];
    return stoi(temp);
}


int rightShift(int number){
    string str = to_string(number);
    if(str.size()!=4){
        while(1){
            if(str.size()==4){
                break;
            }
            str = "0"+str;
        }
    }
    string temp ="";
    for(int i=0; i<3;i++){
        temp+=str[i];
    }
    temp = str[3]+temp;
    return stoi(temp);
}

int main(){
    cin>>T;
    for(int t=0; t<T;t++){
        cin>>a>>b;
        qu.push(Node(a,""));
        int time=0;
        bool answer=false;
        while(!qu.empty()){
            int s= qu.size();
            if(answer) break;
            time++;
            while(s--){
                int number = qu.front().num;
                string str = qu.front().str;
                qu.pop();
                if(number == b){
                    cout<<str<<'\n';
                    answer=true;
                    break;
                }
                int newNumber = number*2>10000?(number*2)%10000 : number*2;
                qu.push(Node(newNumber,str+"D"));
                newNumber = number-1<0?9999:number-1;
                qu.push(Node(newNumber,str+"S"));
                newNumber = leftShift(number);
                qu.push(Node(newNumber,str+"L"));
                newNumber = rightShift(number);
                qu.push(Node(newNumber,str+"R"));
            }
        }
    }
}
