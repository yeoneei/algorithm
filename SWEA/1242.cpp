//
//  1242.cpp
//  backjoon
//
//  Created by 조연희 on 18/01/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

int T;
int n, m;
int s;
bool check = false;
bool bit[64];
int len[64];
int getReuslt(string pw) {
    check = false;
    int bitIdx = 0;
    int t ,s=0;
    //16진수로 바꾸기
    for (int i = 0; i < pw.size(); i++) {
        if (pw[i] >= 'A') {
            t = 10 + pw[i] - 'A';
        }
        else {
            t = pw[i] - '0';
        }
        s = 3;
        while (s >= 0) {
            bit[bitIdx++]=(t&(1 << s));
            s--;
        }
    }
    
    
    //길이 압축
    int sum = 1;
    int lenIdx = 0;
    for (int i = 1; i <bitIdx; i++) {
        if (bit[i] == bit[i - 1]) sum++;
        else {
            len[lenIdx++] = sum;
            sum = 1;
        }
    }
    
    // 압호찾기
    int pd[9];
    int l = 0;
    int ret = 0;
    if (bit[0]) {
        while (l < 3) {
            ret = ret + len[l++];
        }
        
    }
    else {
        l++;
        while (l < 4) {
            ret = ret*10 + len[l++];
        }
    }
    if (ret == 211) {
        pd[0] = 0;
    }
    else if (ret == 221) {
        pd[0] = 1;
    }
    else if (ret == 122) {
        pd[0] = 2;
    }
    else if (ret == 411) {
        pd[0] = 3;
    }
    else if (ret == 132) {
        pd[0] = 4;
    }
    else if (ret == 231) {
        pd[0] = 5;
    }
    else if (ret == 114) {
        pd[0] = 6;
    }
    else if (ret == 312) {
        pd[0] = 7;
    }
    else if (ret == 213) {
        pd[0] = 8;
    }
    else if (ret == 112) {
        pd[0] = 9;
    }
    
    ret = 0;
    
    for (int i = 1; i < 8; i++) {
        int n = l + 4;
        ret = 0;
        while (l < n) {
            ret = ret * 10 + len[l++];
        }
        if (ret == 3211) {
            pd[i] = 0;
        }
        else if (ret == 2221) {
            pd[i] = 1;
        }
        else if (ret == 2122) {
            pd[i] = 2;
        }
        else if (ret ==1411) {
            pd[i] = 3;
        }
        else if (ret == 1132) {
            pd[i] = 4;
        }
        else if (ret == 1231) {
            pd[i] = 5;
        }
        else if (ret == 1114) {
            pd[i] = 6;
        }
        else if (ret == 1312) {
            pd[i] = 7;
        }
        else if (ret == 1213) {
            pd[i] = 8;
        }
        else if (ret == 3112) {
            pd[i] = 9;
        }
    }
    int n = (pd[0] + pd[2] + pd[4] + pd[6]) * 3 + pd[1] + pd[3] + pd[5] + pd[7];
    if (n % 10 == 0) {
        sum = 0;
        for (int i = 0; i < 8; i++) {
            sum += pd[i];
        }
        return sum;
    }
    else {
        return -1;
    }
    
    return true;
}
bool ansCheck= false;
int ans = -1;
int main() {
    freopen("/Users/yeoni/Desktop/test/backjoon/SWEA/input.txt", "r", stdin);
    cin >> T;
    string temp;
    for (int t = 1; t <= T; t++) {
        cin >> n >> m;
        cin.ignore();
        ansCheck = false;
        ans =-1;
        for (int i = 0; i < n; i++) {
            getline(cin, temp);
            check = false;
            if(ansCheck==true){
                continue;
            }
            for (int j = 0; j < m; j++) {
                if (temp[j] != '0' && check == false) {
                    check = true;
                    s = j;
                }
                else if (check == true && temp[j] == '0') {
                    check = false;
                    ans = getReuslt(temp.substr(s, j - s));
                    if (ans != -1) {
                        ansCheck=true;
                    }
                }
                
            }
        }
        cout << '#' << t << " " << ans << endl;
    }
}
