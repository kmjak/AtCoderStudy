#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, k;
    int c = 0;
    string s;
    cin >> n >> k >> s;
    for (int i = 0; i < n - k - 1; i++)
    {
        cout << s.substr(i, i + k) << endl;
    }
}