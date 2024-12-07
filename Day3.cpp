#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>
#include <regex>

using namespace std;

long long mul(string s){
    long long ans = 1;
    stringstream ss(s);
    string word;
    char del = ',';
    while(!ss.eof()){
        getline(ss, word, del);
        ans *= stoi(word);
    }
    return ans;
}


int main(){
    long long c = 0;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("DAY1.INP","r",stdin);
    string inp;
    while(getline(cin,inp)){
        regex pattern(R"(mul\(\d{1,3},\d{1,3}\))");
        sregex_iterator it(inp.begin(), inp.end(), pattern);
        sregex_iterator end;
        for(; it != end; ++it){
            string onlyNum = it->str().substr(4,it->str().size() - 5);
            //cout << onlyNum << " = " << mul(onlyNum) << endl;
            c += mul(onlyNum);
        }
    }
    cout << c;
    return 0;
}