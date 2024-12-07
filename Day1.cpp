#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("DAY1.INP","r",stdin);
    vector<long long> a,b;
    unordered_map<int,int> mp;
    long long x,y;
    while(cin >> x >> y){
        a.push_back(x);
        mp[y]++;
    }
    long long c = 0;
    for(auto x : a){
        c += x * mp[x];
    }
    cout << c;
    return 0;
}