#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>
using namespace std;

vector<vector<char>> mp;

bool validSquare(int x, int y){
    return(x >= 0 && x < mp[0].size() && y >= 0 && y < mp.size());
}

/*bool isXMAS(int index, string word, int x, int y, int dX, int dY){
    if(index == word.length()){
        return true;
    }
    if(validSquare(x,y) && mp[y][x] == word[index])
        return isXMAS(index+1, word, x+dX, y+dY, dX, dY);
    return false;
}

void Part1(){
    int c = 0;
    char dX[] = {0,1,0,-1,1,1,-1,-1};
    char dY[] = {-1,0,1,0,-1,1,1,-1};

    for(int i = 0; i < mp.size(); i++){
        for(int j = 0; j < mp[i].size(); j++){
            for(int k = 0; k < 8; k++){
                if(isXMAS(0,"XMAS",j,i,dX[k],dY[k]))
                    c++;
            }
        }
    }
    cout << c;
}*/


bool isX_MAS(int r, int c){
    if((!validSquare(r+1,c+1)) || (!validSquare(r-1,c-1)) || (!validSquare(r+1,c-1)) || (!validSquare(r-1,c+1)))
        return false;
    if(!((mp[r+1][c+1] == 'S' && mp[r-1][c-1] == 'M') || (mp[r+1][c+1] == 'M' && mp[r-1][c-1] == 'S')))
        return false;
    if(!((mp[r+1][c-1] == 'S' && mp[r-1][c+1] == 'M') || (mp[r+1][c-1] == 'M' && mp[r-1][c+1] == 'S')))
        return false;
    return true;
}


void Part2(){
    int c = 0;
    for(int i = 0; i < mp.size(); i++){
        for(int j = 0; j < mp[i].size(); j++){
            if(mp[i][j] == 'A' && isX_MAS(i,j))
                c++;
        }
    }
    cout << c;
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("DAY1.INP","r",stdin);
    string inp;
    
    while(getline(cin,inp)){
        mp.push_back({});
        for(auto x:inp)
            mp[mp.size()-1].push_back(x);
    }

    Part2();
    return 0;
}