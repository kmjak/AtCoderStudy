#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> cards(n),costs(n);
    for(int i = 0; i < n; i++){
        cin >> cards.at(i);
        cin >> costs.at(i);
    }
    vector<int> c;
    for(int i = 0; i < n; i++){
        bool flag = true;
        for(int j = 0; j < n; j++){
            if(cards.at(i) > cards.at(j) && costs.at(i) < costs.at(j)){
                flag = false;
            }
        }
        if(flag){
            c.push_back(i+1);
        }
    }
    cout << c.size() << endl;
    for(auto x : c){
        cout << x << " ";
    }
}