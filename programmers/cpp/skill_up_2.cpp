#include <bits/stdc++.h>
using namespace std;

bool isNum(char a){
    return '0'<=a && a<='9';
}

int solution(string dartResult) {
    int answer = 0;

    vector<string> dartList;
    int score[3] = {0,};
    string cur = ""; 
    cur+=dartResult[0];

    for(int i=1; i<dartResult.size(); i++){
        if(isNum(dartResult[i])){
            dartList.push_back(cur);
            cur = dartResult[i];
            continue;
        }
        cur+=dartResult[i];
    }
    dartList.push_back(cur);

    for(int i=0; i<dartList.size(); i++){
        string dart = dartList[i];

        cout << dart << '\n';

        int num = dart[0]-'0';

        if(dart[1]=='D')num = num*num;
        else if(dart[1]=='T')num = num*num*num;
        
        score[i] += num;

        if(dart.size()==2){
            if(dart[2]=='*'){
                for(int j = 0; j<=i; j++){
                    score[j] *= 2;
                }
            }
            else {
                score[i] -= 2*num;
            }
        }
    }

    for(int i=0; i<3; i++){
        answer += score[i];
        cout << score [i] << '\n';
    }

    return answer;
}

int main(){
    return 0;
}