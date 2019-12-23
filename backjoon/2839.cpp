//
//  2839.cpp
//  backjoon
//
//  Created by 조연희 on 25/03/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void div(int num, int count, vector<int> &v){
    if(num ==0){
        v.push_back(count);
        return;
    }else if(num <0){
        v.push_back(-1);
        return;
    }
    
    
    if((num-5)>0){
        int im = count+1;
        div((num-5),im,v);
    }
    
    if((num%3)==0){
        count= count+(num/3);
        v.push_back(count);
        return;
    }
}

int main(){
    int num;
    vector<int> output;
    cin>>num;
    
    int n = num;
    //3,5
    
    if((n%5) ==0){
        output.push_back((n/5));
    }else if((n%3) ==0){
        output.push_back((n/3));
    }
    
    int count=0;
    div(num, count, output);
    
    if(output.size()==0){
        cout<<-1<<endl;
    }else{
        sort(output.begin(),output.end());
        int i=0;
        bool tr = false;
        for(i=0; i<output.size(); i++){
            if(output.at(i)!=-1){
                cout<<output.at(i)<<endl;
                tr =true;
                break;
            }
        }
        if(tr == false){
            cout<<-1<<endl;
        }
    }

}
