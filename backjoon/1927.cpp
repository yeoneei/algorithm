//
//  1927.cpp
//  backjoon
//
//  Created by 조연희 on 23/07/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

int arr[100001];
void quick_sort(int *data, int start, int end){
    if(start >= end){
        return;
    }
    
    int pivot = start;
    int i = pivot + 1;
    int j = end;
    int temp;
    
    while(i <= j){
        while(i <= end && data[i] <= data[pivot]){
            i++;
        }
        while(j > start && data[j] >= data[pivot]){
            j--;
        }
        
        if(i > j){
            temp = data[j];
            data[j] = data[pivot];
            data[pivot] = temp;
        }else{
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }
    
    quick_sort(data, start, j - 1);
    quick_sort(data, j + 1, end);
}
int cont;
int main(){
    int n;
    cin>>n;
    for(int i=0; i<n;i++){
        int tmep;
        cin>>temp;
        
    }
}
