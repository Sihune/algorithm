#include <bits/stdc++.h>
using namespace std;

bool search(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t, long long m){
    long long gold=0, silver=0;
    long long total=0;

    for(int i=0; i<g.size(); i++){
        long long Time = t[i];

        long long round_time = Time*2;
        long long move = m/round_time;
        if(m%round_time>=Time)move++;
        
        long long take = w[i]*move;

        gold += min((long long)g[i], take);
        silver += min((long long)s[i], take);
        total += min((long long)g[i]+s[i], take); // gold+silver 갯수 총합이 움직인 개수이하거나 같아야한다.
    }
    if(gold>=a && silver>=b && total>=a+b)return true;
    return false;
}

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long S = 0;
    long long E = 10e14*3;
    long long answer = E;

    while(S<=E){
        long long m = (S+E)>>1;

        if(search(a,b,g,s,w,t,m)){
            answer = min(answer,m);
            E = m-1;
        }
        else S = m+1;
    }
    
    return answer;
}

int main(){
    return 0;
}