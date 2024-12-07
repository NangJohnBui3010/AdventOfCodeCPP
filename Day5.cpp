#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <string>
#include <sstream>
using namespace std;

unordered_map<int, unordered_set<int>> mp;

vector<int> strSplit(string s){
    vector<int> ans;
    stringstream ss(s);
    string word;
    while(!ss.eof()){
        getline(ss, word, ',');
        ans.push_back(stoi(word));
    }
    return ans;
}

void getOrder(){
    string s;
    while(getline(cin, s)){
        if(s != ""){
            int num1 = stoi(s.substr(0,2));
            int num2 = stoi(s.substr(3,2));
            mp[num1].insert(num2);
        }else break;
    }
}

void Part1(){
    cout <<"\n\nAnswers: " << endl;
    getOrder();
    string s;
    vector<int> arr;
    long long c = 0;
    while(getline(cin,s)){
        bool check = true;
        arr = strSplit(s);
        for(int i = 1; i < arr.size(); i++){
            for(int j = 0; j < i; j++)
                if(mp[arr[i]].find(arr[j]) != mp[arr[i]].end()){
                    check = false;
                    break;
                }
            if(!check) break;
        }
        for(auto x:arr)
            cout << x  << " ";
        cout << endl;
        if(check){
            cout << "True" << endl;
            c += arr[arr.size()/2];
        }else cout <<"False" << endl;
        
    }
    cout << "Final answer" << c << endl;
}

bool cmp(int a, int b){
    return(mp[a].find(b) != mp[a].end());
}

void Part2(){
    cout <<"\n\nAnswers: " << endl;
    getOrder();
    string s;
    vector<int> arr;
    long long c = 0;
    while(getline(cin,s)){
        bool check = true;
        arr = strSplit(s);
        for(int i = 1; i < arr.size(); i++){
            for(int j = 0; j < i; j++)
                if(mp[arr[i]].find(arr[j]) != mp[arr[i]].end()){
                    check = false;
                    break;
                }
            if(!check) break;
        }
        for(auto x:arr)
            cout << x  << " ";
        cout << endl;
        if(check){
            cout << "True" << endl;
        }else{
            cout <<"False" << endl;
            sort(arr.begin(), arr.end(), cmp);
            c += arr[arr.size()/2];
        } 
        
    }
    cout << "Final answer" << c << endl;
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