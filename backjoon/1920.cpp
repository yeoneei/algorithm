//
//  1920.cpp
//  backjoon
//
//  Created by 조연희 on 23/07/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

int arr[100000];
bool binarySearch(int* arr, int low, int high, int target)
{
    int mid;
    if (low > high)
    {
        return false;
    }
    mid = (low + high) / 2;
    
    if(target == arr[mid]){
        
        return true;
    }else if (target < arr[mid])
    {
        binarySearch(arr, low, mid - 1, target);
    }
    else if (arr[mid] < target)
    {
        binarySearch(arr, mid + 1, high, target);
    }
}

void quickSort(int *arr, int first, int last)
{
    int pivot;
    int i;
    int j;
    int temp;
    
    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;
        
        while (i < j)
        {
            while (arr[i] <= arr[pivot] && i < last)
            {
                i++;
            }
            while (arr[j] > arr[pivot])
            {
                j--;
            }
            if (i < j)
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        
        temp = arr[pivot];
        arr[pivot] = arr[j];
        arr[j] = temp;
        
        quickSort(arr,first, j - 1);
        quickSort(arr,j + 1, last);
    }
}
int main(){
    int n;
    scanf("%d", &n);
    for(int i=0; i<n;i++){
        scanf("%d",&arr[i]);
    }
    quickSort(arr, 0,n-1);
    int m,temp;
    bool ch;
    scanf("%d", &m);
    for(int i=0; i<m;i++){
        scanf("%d", &temp);
        ch = binarySearch(arr, 0, n-1, temp);
        if(ch==true){
            printf("1\n");
        }else{
            printf("0\n");
        }
    }
    
}


