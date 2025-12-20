#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long int c;
    long long int s_x, s_y, t_x, t_y;
    cin >> s_x >> s_y >> t_x >> t_y;
    s_x++;
    s_y++;
    t_x++;
    t_y++;
    if (s_x % 2 == 0)
    {
        if (s_y % 2 == 1)
        {
            s_x--;
        }
    }
    else
    {
        if(s_y % 2 == 0){
            s_x--;
        }
    }
    long long int x = abs(s_x - t_x);
    long long int y = abs(s_y - t_y);
    long long int m = min(x,y);
    if(s_x > t_x){
        s_x -= m;
    }else{
        s_x += m;
    }
    if(s_y > t_y){
        s_y -= m;
    }else{
        s_y += m;
    }
    c = m;
    if(s_x == t_x){
        c += abs(abs(t_y) - abs(s_y));
    }else{
        c += abs(abs(t_x) - abs(s_x)) / 2 - 0.5;
    }
    cout << c << endl;
}