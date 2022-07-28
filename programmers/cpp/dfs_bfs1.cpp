#include <bits/stdc++.h>
using namespace std;

int T,N;
int answer;
vector<int> number;

void dfs(int cur, int num){
    if(cur == N){
        if(num == T)answer++;
        return;
    }

    dfs(cur+1, num + number[cur]);
    dfs(cur+1, num - number[cur]);
}

int solution(vector<int> numbers, int target) {

    T = target, N = numbers.size();
    number = numbers;

    dfs(0, 0);

    return answer;
}

int main(){
    return 0;
}