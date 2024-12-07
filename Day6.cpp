#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>
using namespace std;

vector<vector<char>> mp;
vector<vector<bool>> marked;
int r,c;

bool validSquare(int x, int y){
    return(x >= 0 && x < mp[0].size() && y >= 0 && y < mp.size());
}

void printMP(vector<vector<char>> mp){
    for(auto x : mp){
        for(auto y : x)
            cout << y;
        cout << endl;
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("DAY1.INP","r",stdin);
    string inp;
    while(getline(cin,inp)){
        mp.push_back({});
        for(auto x:inp){
            mp[mp.size()-1].push_back(x);
            if(x == '^'){
                r = mp.size()-1;
                c = mp[mp.size()-1].size()-1;
            }
        }
    }

    int dX[] = {0,1,0,-1};
    int dY[] = {-1,0,1,0};
    int curD = 0;
    int cnt = 1;
    int r1 = r, c1 = c;
    while(true){
        while(validSquare(c1,r1) && mp[r1][c1] != '#'){
            if(mp[r1][c1] != '^'){
                mp[r1][c1] = '^';
                cnt++;
                //printMP(mp);
                //cout << endl;
            }
            r1 += dY[curD];
            c1 += dX[curD];
        }
        if(!validSquare(r1,c1))
            break;
        else{
            r1 -= dY[curD];
            c1 -= dX[curD];
            curD = (curD+1)%4;
            r1 += dY[curD];
            c1 += dX[curD];
        }
    }
    cout << cnt;
    //cout << r << " " << c;
    return 0;
}