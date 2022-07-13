#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> phone_map;

bool solution(vector<string> phone_book) {
    bool answer = true;

    for(auto number: phone_book){
        phone_map[number]++;
    }

    for(auto number: phone_book){
        string cur="";
        for(int i=0; i<number.size()-1; i++){
            cur+=number[i];
            if(phone_map[cur])return false;
        }
    }

    return true;
}

int main(){
    vector<string> phone_book = {"119", "97674223", "1195524421"};
    cout << solution(phone_book)<<'\n';

    return 0;
}