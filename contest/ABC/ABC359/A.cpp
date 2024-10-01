#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int c = 0;
    cin >> n;
    string temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        if (temp == "Takahashi")
        {
            c++;
        }
    }
    cout << c << endl;
}