#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


void Part1(){
    vector<int> a,b;
    int x,y;
    while(cin >> x >> y){
        a.push_back(x);
        b.push_back(y);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long long c = 0;
    for(int i = 0; i < a.size(); i++)
        c += abs(a[i]-b[i]);
    cout << c;
}

void Part2(){
    vector<long long> a;
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
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("DAY1.INP","r",stdin);
    //Part1();
    //Part2();
    return 0;
}