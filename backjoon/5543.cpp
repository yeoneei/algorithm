//
//  5543.cpp
//  backjoon
//
//  Created by 조연희 on 12/03/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

long long sum(int *a, int n){
    long long answer=0;
    for(int i=0; i<n;i++){
        answer+=a[i];
    }
    return answer;
}
