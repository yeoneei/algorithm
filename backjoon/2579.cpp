//
//  2579.cpp
//  backjoon
//
//  Created by 조연희 on 20/08/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <string.h>
using namespace std;

int arr[300];
int cache[301];

int n;
int step(int s,bool check){
    if(s==0) return arr[0];
    if(s<0) return 0;
    int &ret = cache[s];
    if(ret!=-1) return ret;
    if(check== true) ret = max(step(s-2,true),step(s-1,false))+arr[s];
    if(check == false) ret = step(s-2,true)+arr[s];
    cout<<s<<" "<<ret<<endl;
    return ret;
}

void init(){
    memset(cache, -1, sizeof(cache));
}
int main(){
    cin>>n;
    for(int i=0; i<n;i++){
        cin>>arr[i];
    }
    init();
    cout<<step(n-1,true)<<endl;

}
