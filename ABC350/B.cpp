#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n,q;
    cin >> n >> q;
    set<int> d;
    int temp;
    for(int i = 0; i < q; i++){
        cin >> temp;
        if(d.count(temp)){
            d.erase(temp);
        }else{
            d.insert(temp);
        }
    }
    cout << d.size() << endl;
}