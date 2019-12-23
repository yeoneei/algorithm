//
//  1764.cpp
//  backjoon
//
//  Created by 조연희 on 23/07/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#define HASH_MAX 10007
#define Node_MAX 500001
#define Name_MAX 500001

struct Node{
    char name[20];
    Node *next;
    
};
Node node[Node_MAX];
Node *hashTable[HASH_MAX];
char* DBJ[Name_MAX];
char* tempDBJ[Name_MAX ];

int strLen(char * str){
    int i=0;
    while(str[i]!=0){
        i++;
    }
    return i;
}

int strcmp(char *des, char*src){
    while(*des == *src && *src){
        ++des;++src;
    }
    return *des-*src;
}
int myHash(char *name){
    int mul=1;
    int x= 0;
    int size = strLen(name);
    for(int i=0; i<size;i++){
        x = ((name[i]*mul)+x) % HASH_MAX;
        mul*=1007;
    }
    if(x<0) x = -x;
    if(x> HASH_MAX) x=x%HASH_MAX;
    return x;
}
void strcpy(char *des, char *src){
    while(*des!=0){
        *src++=*des++;
    }
    *src=0;
}

void quickSort(int first, int last, char *data[Name_MAX])
{
    int pivot;
    int i;
    int j;
    char *temp;
    
    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;
        
        while (i < j)
        {
            while (*data[i] <= *data[pivot] && i < last)
            {
                i++;
            }
            while (*data[j] > *data[pivot])
            {
                j--;
            }
            if (i < j)
            {
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
        
        temp = data[pivot];
        data[pivot] = data[j];
        data[j] = temp;
        
        quickSort(first, j - 1,data);
        quickSort(j + 1, last,data);
    }
}
int main(){
    int N,M;
    int count=0;
    scanf("%d %d", &N,&M);
    char name[21];
    for(int i=0; i<N;i++){
        scanf("%s", name);
        
        Node *temp = new Node;
        strcpy(name, temp->name);
        
        int key = myHash(name);
        temp->next = hashTable[key];
        hashTable[key]= temp;
    }
    
    for(int i=0; i<M;i++){
        scanf("%s",name);
        
        int key = myHash(name);
        
        for(Node *pp = hashTable[key];pp;pp=pp->next){
            if(strcmp(name, pp->name)==0){
                DBJ[count++]=pp->name;
            }
        }
        
    }
    printf("%d\n", count);
    quickSort(0, count-1, DBJ);
    for(int i = 0; i < count; ++i){
        printf("%s\n", DBJ[i]);
    }
}
