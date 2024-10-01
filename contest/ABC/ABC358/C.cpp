#include <bits/stdc++.h>
using namespace std;
int f(int n, int c)
{
    if(c == 1){
        return n;
    }
    return n * f(n-1,c-1);

}
int main()
{
    int n,p;
    cin >> n >> p;
    vector<vector<char>> shop(n,vector<char> (p));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < p; j++){
            cin >> shop.at(i).at(j);
        }
    }
    int c = 1;
    while(true){
        vector<int> counter(c);
        for(int j = 0; j < c; j++){
            counter.at(j) = j;
        }
        for(int i = 0; i < f(n,c); i++){
            vector<int> popcorn(p,0);
            for(int j = c - 1; j > 0; j--){
                if(counter.at(j) >= n){
                    counter.at(j-1)++;
                    counter.at(j) = 0;
                }
                for(int k = 0; k < c; k++){
                    if(j != k && counter.at(j) == counter.at(k)){
                        if(j < k){
                            counter.at(k)++;
                            j = k+1;
                            break;
                        }else{
                            counter.at(j)++;
                            j++;
                            break;
                        }
                    }
                }
            }
            for(auto x : counter){
                for(int k = 0; k < p; k++){
                    if(shop.at(x).at(k) == 'o'){
                        popcorn.at(k) = 1;
                    }
                }
            }
            if(count(popcorn.begin(),popcorn.end(),1) == p){
                cout << c << endl;
                return 0;
            }
            counter.at(c-1)++;
        }
        c++;
    }
}