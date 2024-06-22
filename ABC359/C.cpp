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
    long long int a_x = abs(s_x - t_x);
    long long int a_y = abs(s_y - t_y);
    long long int m = min(a_x, a_y);
    c = m;
    s_x = abs(s_x) - m;
    s_y = abs(s_y) - m;
    if (s_x == t_x)
    {
        c += abs(s_y);
    }
    else
    {
        c += abs(s_x - t_x) / 2 - 0.5;
    }
    if (s_y % 2 == 1)
    {
        if (s_x < t_x)
        {
            c++;
        }
    }
    cout << c << endl;

    // while (s_x != t_x && s_y != t_y)
    // {
    //     if (s_y % 2 == 0)
    //     {
    //         if (s_x < t_x)
    //         {
    //             s_x++;
    //         }
    //     }
    //     else
    //     {
    //         if (s_x > t_x)
    //         {
    //             s_x--;
    //         }
    //     }
    //     if (s_y > t_y)
    //     {
    //         s_y--;
    //         c++;
    //     }
    //     else
    //     {
    //         s_y++;
    //         c++;
    //     }
    // }
    // if (s_x == t_x)
    // {
    //     c += abs(s_y - t_y);
    // }
    // else
    // {
    //     c += abs(s_x - s_y) / 2 - 0.5;
    // }
    // cout << c << endl;
}