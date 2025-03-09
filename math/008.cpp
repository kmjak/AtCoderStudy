#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,s;
    int c = 0;
    cin >> n >> s;
    for(int i = 1; i < n + 1; i++){
        for(int j = 1; j < n + 1; j++){
            if(i + j <= s)c++;
            else break;
        }
    }
    cout << c << endl;
}