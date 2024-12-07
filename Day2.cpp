#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <sstream>
using namespace std;


int c = 0;

vector<int> removed(vector<int> arr, int index){
    vector<int> ans;
    for(int i = 0; i < arr.size(); i++){
        if(i != index)
            ans.push_back(arr[i]);
    }
    return ans;
}

vector<int> StringToVector(string s){
    vector<int> ans;
    stringstream ss(s);
    string word;
    while(ss >> word){
        ans.push_back(stoi(word));
    }
    return ans;
}

void Solve(vector<int> m){
    int direction;
    vector<int> arr;
    int n = m.size();
    for(int j = -1; j < n; j++){
        bool check = true;
        arr = removed(m,j);
        for(auto x : arr)
            cout << x << " ";
        cout << endl;
        if(arr[1] > arr[0])
            direction = 1; //ascending
        else if (arr[1] < arr[0])
            direction = -1; // descending
        else
            continue;
        if(abs(arr[0] - arr[1]) > 3)
            continue;
        for(int i = 2; i < arr.size(); i++){
            if(direction == 1 && arr[i] <= arr[i-1]){
                check = false;
                break;
            }
            if(direction == -1 && arr[i] >= arr[i-1]){
                check = false;
                break;
            }
            if(abs(arr[i] - arr[i-1]) > 3){
                check = false;
                break;
            }
        }
        if(check){
            c++;
            cout << "SAFE" << endl;
            return;
        }
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("DAY1.INP","r",stdin);
    string inp;
    vector<int> arr;
    while(getline(cin,inp)){
        arr = StringToVector(inp);
        //cout << arr[arr.size()-1] << endl;
        Solve(arr);
    }
    cout << c;
}