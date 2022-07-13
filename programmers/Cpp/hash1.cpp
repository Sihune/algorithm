#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> part;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";


    for(auto c: completion){
        part[c]++;
    }
    for(auto p: participant){
        part[p]--;
        if(part[p]<0){
            answer = p;
            break;
        }
    }

    return answer;
}

int main(){
    return 0;
}