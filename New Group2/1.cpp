
//
//  1.cpp
//  backjoon
//
//  Created by 조연희 on 28/03/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#define MAX 30
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int size = (int)board.size();
    vector<int> endBoard;
    endBoard.resize(size+1);
    for(int i=0; i<size;i++){
        int idx=size;
        while(board[idx-1][i]!=0){
            idx--;
            if(idx==0)break;
        }
        endBoard[i]=idx;
    }
    vector<int> list;
    for(int i=0; i<moves.size();i++){
        if(endBoard[moves[i]-1]==size)continue;
        list.push_back(board[endBoard[moves[i]-1]][moves[i]-1]);
        board[endBoard[moves[i]-1]][moves[i]-1]=0;
        endBoard[moves[i]-1]++;
        if(list.size()<=1)continue;
        if(list[list.size()-1]==list[list.size()-2]){
            answer+=2;
            list.pop_back();
            list.pop_back();
        }
    }
    return answer;
}

int main(){
    vector<vector<int>> board = {{0,0,0,0,0,1},{0,0,0,0,0,1},{0,0,1,0,3,1},{0,2,5,0,1,1},{4,2,4,4,2,1},{3,5,1,3,1,1}};
    vector<int> moves = {1,5,3,5,1,2,1,4};
    
    cout<<solution(board, moves)<<endl;
}
