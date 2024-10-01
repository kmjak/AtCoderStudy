#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    int c = 0;
    cin >> n;
    n *= 2;
    vector<int> h(n);
    for (int i = 0; i < n; i++)
    {
        cin >> h.at(i);
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (h.at(i - 1) == h.at(i + 1))
        {
            c++;
        }
    }
    cout << c << endl;
}