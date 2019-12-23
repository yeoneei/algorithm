
#include<iostream>
#include<string>
using namespace std;

int N;
bool map[101][101];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

int main()
{
    cin >> N;
    
    string str;
    cin >> str;
    
    int dir = 0;
    int cx = 50, cy = 50;
    int sx = cx, sy = cy, ex = cx, ey = cy;
    
    map[cx][cy] = true;;
    
    for (int j = 0; j < N; j++)
    {
        if (str[j] == 'L') dir = (dir + 3) % 4;
        else if (str[j] == 'R') dir = (dir + 1) % 4;
        else if (str[j] == 'F')
        {
            cx += dx[dir];
            cy += dy[dir];
            map[cx][cy] = true;
            
            if (cx < sx) sx = cx;
            if (cy < sy) sy = cy;
            if (cx > ex) ex = cx;
            if (cy > ey) ey = cy;
        }
    }
    
    for (int i = sx; i <= ex; i++)
    {
        for (int j = sy; j <= ey; j++)
        {
            if(map[i][j]) cout << '.';
            else cout << '#';
        }
        cout << '\n';
    }
    
    return 0;
}
