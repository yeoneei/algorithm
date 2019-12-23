//
//  2309.cpp
//  backjoon
//
//  Created by 조연희 on 16/07/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

void quickSort(int *data, int start, int end){
    if(start>= end) return;
    int pivot = start;
    int i= start+1;
    int j = end;
    int temp;
    while(i<=j){
        while(i<=end && data[i]<=data[pivot]){
            i++;
        }
        while(j>start && data[j]>=data[pivot]){
            j--;
        }
        
        if(i>j){
            temp = data[j];
            data[j] = data[pivot];
            data[pivot]= temp;
        }else{
            temp = data[i];
            data[i] = data[j];
            data[j]= temp;
            
        }
    }
    
    quickSort(data, start, j-1);
    quickSort(data,j+1,end);
}

int arr[9];

int main(){
    int sum=0;
    for(int i=0; i<9;i++){
        cin>>arr[i];
        sum+=arr[i];
    }
    bool check =false;
    for(int i=0;i<9;i++){
        if(check==true){
            break;
        }
        for(int j=0;j<9;j++){
            if(i==j){
                continue;
            }
            int temp = sum-arr[i]-arr[j];
            if(temp==100){
                arr[i]=0;
                arr[j]=0;
                check = true;
                break;
            }
        }
    }
    
    quickSort(arr, 0, 8);
    for(int k=2;k<9;k++){
        cout<<arr[k]<<endl;
    }
    
}
